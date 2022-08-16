#include <netinet/in.h>
#include <string.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <stdlib.h>
#include <unistd.h>
char *tarjeta_red;
int  salida;    
char comando[60];
socklen_t Longituc_Estructura;
int domain, type, protocol,MiSocket,i,Socket_Conexion_Cliente,h;
char Codigo_ascii[17];
struct sockaddr_in Miservidor, Mi_Cliente;
char buferIntercambio[90];
void lafunc(int chatServClient);
