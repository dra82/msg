#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>

#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>

#define BUFFERSIZE 1024

using namespace std;

int main(int argc, char* argv[]){
	cout << "Hello. Server here." << endl;
	/* check args */
	if ( argc < 2 ){
		cout << "Usage:\n ./server <PORT>" << endl;
		exit(1);
	}
	
	int port;		//listening port
	int sockFd, newSockFd;	//File-Descriptors for sockets

	unsigned char buffer[BUFFERSIZE];
	
	struct sockaddr_in serverAddr, clientAddr;	// Struct from 'netinet/in.h'
	
	/* Create socket */
	sockFd = socket( AF_INET, SOCK_STREAM, 0);	// socket (ADDRESS-FAMILY:=IPv4), 
							// SOCKET-TYPE:=TCP(because no other Steram-Sockets in IPv4 ),
							// PROTOCLO-TYPE:=TCP (no other protocol possible so '0' uses defaultvalue)
	if (sockFd < 0){
		cerr << "ERROR opening socket." << endl;
		exit (1);
	}
	
	bzero((char*) &serverAddr, sizeof(serverAddr));	// bzero := write zero-valued bytes
	if (atoi(argv[1]) > 0 && atoi(argv[1] < 65537){
		port = atoi(argv[1]);				// TODO: Cehck value!
	}
	
	
	return 0;
} 
