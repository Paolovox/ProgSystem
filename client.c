#include "system.h"


int main(int argc, char** argv)
{
  
  int r;
  char *op, *path;

  // se gli argomenti sono due, allora sarà un comando seguito
  //da un path (-op path), altrimenti sarà il comando per mettersi solo in ascolto (-w)
  if( argc == 3 )
    {
      op = argv[1]; path = argv[2];
    }
  else if( argc == 2 )
    {
      op = argv[1]; path = NULL;
    }
  else
    {
      printf("ERROR: [-op] <path>");
      return -1;
    }

  
  
  // Connetto al server e ottengo il descriptor del server
  SOCKET server = clientTCP();
  if( server < 0 ) { printf("ERROR: connection TCP failed"); return -1; }



  // Comincio gli scambi di messaggi tra client e server, in base all'op e al path
  // Nella funzione proto, il client si mette in ascolto su una porta UDP
  // per ricevere gli aggiornamenti del server.
  r = proto(server, op, path );
  if( r == -1 ) { printf("ERROR: protocol failed"); return -1; }


  return 0;
}
