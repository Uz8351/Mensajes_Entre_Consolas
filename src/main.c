

#include"Variables_Servidor.h"

int main()
{
printf("\n");
printf("--------------------------------------------------\n"); 
printf("***********CARACTERISTICAS DE LA RED**********\n" );
printf("--------------------------------------------------\n"); 
sprintf (comando, "ifconfig");
salida = system (comando);

domain=PF_INET;
type=SOCK_STREAM;
protocol=0;
//void Sabe_Tipo_Red();//Llamada configuración de Red.
MiSocket= socket (  domain,   type,   protocol);
//printf("domain: %d type:%d  protocol:%d  socket:%i Descriptor Socket:%d \n",domain,type,protocol,socket,MiSocket);
if (MiSocket == -1)
{
printf("Hubo un error al abrir el socket\n");
}
else
	printf("Socket abierto con éxito\n" );


/*
   Para una aplicación de socket que usa el Protocolo de Internet versión 4 (IPv4),
   la familia de direcciones AF_INET usa la estructura de direcciones sockaddr_in
   como expresión típica:
   strucServidor.sin_family = AF_INET;
   strucServidor.sin_port = htons(Puerto);
   strucServidor.sin_addr.s_addr = inet_addr(IP);
   */

printf("Número de puerto elegido para la IP:8358\n");

Miservidor.sin_family = AF_INET; /* Familia de direcciones */
Miservidor.sin_port = htons(8358); /* Ordenación de la red */
//my_addr.sin_addr.s_addr = inet_addr ("192.168.0.27); activar opcion IP
//Miservidor.sin_addr.s_addr = inet_addr("127.0.0.1"); activar opción IP
Miservidor.sin_addr.s_addr = INADDR_ANY;//Cualquier IP.
/* Pone a cero el resto de la estructura  -Activar para otras pruebas*/
//memset(&(Miservidor.sin_zero), '\0', 8);-Activar para otras pruebas
/* Chequear si devuelve -1 que indica no enlazado! */

//if ((bind(sockDescriptor, (struct sockaddr *)&strucServidor, sizeof(strucServidor))) != 0)
printf("Asociado:Puerto, IP y Socket (con exito si la salida es=0, y no asociado si es igual:-1) --> %i\n",(bind(MiSocket, (struct sockaddr *)&Miservidor, sizeof(Miservidor))));

if ((bind(MiSocket, (struct sockaddr *)&Miservidor, sizeof(Miservidor)))==!0)
{
	
	printf("Asociado:Puerto, IP y Socket.\n");
	 
}


listen(MiSocket,5);//int listen(int sockfd, int backlog);

//int backlog, es el número de clientes de cola.
//*****************************************
//---------------ACCEP()----------------------------
/*
--------------------------------------------------------------------
La llamada accept() al sistema  se usa con socket basado en conexión
        tipos (SOCK_STREAM, SOCK_SEQPACKET). Se extrae la primera
        solicitud de conexión en la cola de conexiones pendientes para el
        conector de escucha, sockfd, crea un nuevo descriptor 
        de archivo que hace referencia a ese socket.
        El socket recién creado no está en estado de escucha. El original
        socket "MiSocket"-inicial- no se ve afectado por esta llamada.

        El argumento "sockfd" es un socket que ha sido creado con
        socket(2), vinculado a una dirección local con bind(2), y es
        escuchando conexiones después de una segunda escucha .

        El argumento "addr" es un puntero a una estructura sockaddr. Esta
        estructura se rellena con la dirección del socket 
        conocido por la capa de comunicaciones. El formato exacto de la
        la dirección devuelta por addr está determinada por la dirección
        del socket

        El argumento "addrlen" es un argumento que el cliente que llama
        a conexión debe iniciarlo para que contenga el tamaño (en bytes)
        de la estructura  apuntada por addr; conteniendo el tamaño real de
        la dirección de conexión.
        
        */
Socket_Conexion_Cliente=accept(MiSocket,(struct sockaddr *)&Socket_Conexion_Cliente, &Longituc_Estructura);

if(Socket_Conexion_Cliente<0)
  {
    printf("Hubo un error al aceptar comunicación\n");
    
    return 1;
  }
  //**********************************************************
lafunc( Socket_Conexion_Cliente); //Llamada rutina chat.

//close(Socket_Conexion_Cliente);
  }
