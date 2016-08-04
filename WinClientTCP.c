#include "system.h"


SOCKET clientTCP()
{
  WSADATA wsa;	//struttura contenente informazioni sulla socket

  SOCKET s;

  struct sockaddr_in server;

	
   //inizializzazione della socket
  if (WSAStartup(MAKEWORD(2,2),&wsa) != 0) 
    {
        printf("Failed. Error Code : %d",WSAGetLastError());
        return -1;
    }

  printf("Inizializzata.");


  if((s = socket(AF_INET , SOCK_STREAM , 0 )) == INVALID_SOCKET)
    {
        printf("Could not create socket : %d" , WSAGetLastError());
    }
 
   printf("Socket created.\n");

   server.sin_addr.s_addr = inet_addr("127.0.0.1");
   server.sin_family = AF_INET;
   server.sin_port = htons( 8088 );

    
   //Connessione al server remoto
   if (connect(s , (struct sockaddr *)&server , sizeof(server)) < 0)
     {
        puts("connect error");
        return -1;
     }
     
   puts("Connected");

   
  return s; 
}
