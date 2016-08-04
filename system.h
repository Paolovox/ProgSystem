#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// WINDOWS
#ifdef _WIN32
#include <windows.h>
#include <winsock2.h>
#include "WinClientTCP.h"
#include "Proto.h"

#define SALUTA printf("CIAO by WIN\n");

//LINUX
#else
#define SALUTA printf("CIAO by UNIX\n");

#endif
