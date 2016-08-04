#include "system.h"

int proto(SOCKET srv, char *op, char *path)
{

  printf("SOCKET: %d OP:%s, PATH:%s\n\n",srv,op,path);
  /*
  WSADATA wsa;	//struttura contenente informazioni sulla socket
  SOCKET s, new_socket;
  struct sockaddr_in server, client;
  char reply[512];
  
  //inizializzazione della socket
  if (WSAStartup(MAKEWORD(2,2),&wsa) != 0) 
    {
      printf("Failed. Error Code : %d",WSAGetLastError());
      return NULL;
    }

  //inizializzazione socket
  if((s = socket(AF_INET , SOCK_DGRAM , IPPROTO_UDP )) == INVALID_SOCKET)
    {
      printf("Could not create socket : %d" , WSAGetLastError());
    }

  //Prepara la sockaddr_in structure
  server.sin_family = AF_INET;
  server.sin_addr.s_addr = INADDR_ANY;
  server.sin_port = htons( 9090 );

    
  //Bind: lega la socket ad un particolare indirizzo e numero di porta
  if( bind(s ,(struct sockaddr *)&server , sizeof(server)) == SOCKET_ERROR)
    {
      printf("Bind failed with error code : %d" , WSAGetLastError());
    }
     
  //Listen to incoming connections
  if (  listen(s , 1) != 0 ) {  printf("Listen failed with error code : %d" , WSAGetLastError()); } ;

  int c = sizeof(struct sockaddr_in);

  
  switch(op)
    {

    case "-r" :
      send(srv, "INFO", strlen("INFO"), 0);
      //    send(srv, path, strlen(path), 0);
       while ( (new_socket = accept(s , (struct sockaddr *)&client, &c)) != INVALID_SOCKET )
      {
	recv( new_socket, reply, 512, 0 );
	printf("%s\n", reply);
      }
      
      break;

    case "-d":
      break;


    default:
      break;

    }

  
  //chiudo la socket e rilascio disalloco le risorse utilizzate
  closesocket(s);
  WSACleanup();*/
  
  return 0;
}

