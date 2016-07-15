#include <stdlib.h>
#include <stdio.h>
#include <winsock2.h>

#pragma comment(lib,"ws2_32.lib") //dovrebbe dire al linker di utilizzare la libreria

int create_win_socket()
{
	WSADATA wsa;	//struttura contenente informazioni sulla socket

	printf("Inizializzazione...");

		/*
		 * The WSAStartup function is used to start or initialise winsock library.
		 * It takes 2 parameters ; the first one is the version we want to load
		 * and second one is a WSADATA structure which will hold additional
		 * information after winsock has been loaded.
		 */

	    if (WSAStartup(MAKEWORD(2,2),&wsa) != 0)	//inizializzazione socket
	    {
	        printf("Failed. Error Code : %d",WSAGetLastError());
	        return -11;
	    }

	printf("Inizializzata.");

	return 0;
}

//il prossimo step sarebbe creare la socket vera e propria. Ma il problema è caricare
//la libreria ws2_32.dll
