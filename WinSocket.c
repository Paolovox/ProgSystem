#include <stdlib.h>
#include <stdio.h>
#include <winsock2.h>
#include <windows.h>


// argomenti da passare al task eseguito dal thread
typedef struct{
  SOCKET s;
  const char *buf;
  int len;
}Args;


// task eseguito dal thread (insensato solo per vedere se funziona il multithreading) 
int safe_send( Args *a)
{
  int iResult;

  printf("ARGS = %s %d", a->buf, a->len);
  iResult = send( a->s, a->buf, a->len, 0);

  int i;
  for ( i=0 ; i< 10000000 ; i++ )
    {
      char *c = "ciao";
      send( a->s, c ,strlen("ciao") ,0);
    }
  return ( iResult==SOCKET_ERROR ) ?  -1 : 0;

}

//Socket Windows
int create_win_socket()
{
	WSADATA wsa;	//struttura contenente informazioni sulla socket
	SOCKET s, new_socket;
	int c , r = 0;
	char *message;
	struct sockaddr_in server, client;

	printf("Inizializzazione...");

	
	 //inizializzazione della socket
	if (WSAStartup(MAKEWORD(2,2),&wsa) != 0) 
	    {
	        printf("Failed. Error Code : %d",WSAGetLastError());
	        return -1;
	    }

	printf("Inizializzata.");


	//inizializzazione socket
	if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
	  {
	    
        printf("Could not create socket : %d" , WSAGetLastError());
	
	  }
 
    printf("Socket created.\n");


    //Prepara la sockaddr_in structure
    server.sin_family = AF_INET;
    server.sin_addr.s_addr = INADDR_ANY;
    server.sin_port = htons( 8080 );

    
    //Bind: lega la socket ad un particolare indirizzo e numero di porta
    if( bind(s ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
    {
        printf("Bind failed with error code : %d" , WSAGetLastError());
    }
     
    puts("Bind done");


     //Listen to incoming connections
    if (  listen(s , 3) != 0 ) {  printf("Listen failed with error code : %d" , WSAGetLastError()); } ;
     
    //Accept and incoming connection
    puts("Waiting for incoming connections...");
     
    c = sizeof(struct sockaddr_in);
     
    while ( (new_socket = accept(s , (struct sockaddr *)&client, &c)) != INVALID_SOCKET )
      {
        puts("Connection accepted");
	message = "Hello Client";

	//preparo gli argomenti da passare al thread
	Args *a = malloc(sizeof(Args));
	a->buf = message;
	a->len = strlen(message);
	a->s = new_socket;


	// creo un nuovo thread per ogni richiesta accettata fatta da un client e accettata dal server
	if  ( CreateThread(NULL , 0, (LPTHREAD_START_ROUTINE)safe_send , a, 0, NULL) == NULL ) printf("ERROR THREAD");
	
        //Spedisce al client
       
	//      r = safe_send(new_socket , message , strlen(message));
	//	if ( r == -1 ) printf("ERROR");
      }  
     
    if (new_socket == INVALID_SOCKET)
    {
        printf("accept failed with error code : %d" , WSAGetLastError());
        return 1;
    }

    //chiudo la socket e rilascio disalloco le risorse utilizzate
    closesocket(s);
    WSACleanup();
    
    return 0;
}


//test socket windows
int main()
{
  return create_win_socket();
}
