#include "OGLPong.h"
using namespace std;
void clientHandler(SOCKET);

void mainSocket(int value){
	
	int port = 1234;
	SOCKADDR_IN address;
	address.sin_addr.s_addr = inet_addr("127.0.0.1");
	address.sin_family = AF_INET;
	address.sin_port = htons(port);
	
	SOCKET gameSocket = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if( bind(gameSocket, (SOCKADDR*)&address, sizeof(address)) < 0){
		cout<<"Failed bind socket"<<endl;		
	}
	DWORD nonblock = 1;
	if(ioctlsocket(gameSocket, FIONBIO, &nonblock) != 0){
		cout<<"Failed non blocking socket"<<endl;
	}
	
	clientHandler(gameSocket);
	closesocket(gameSocket);
//	glutTimerFunc(1, &mainSocket, 1);
}

void clientHandler(SOCKET sockett){
	SOCKET sock = sockett;
	char msg[64] = "OK";
	while(true){
		char packet[256];
		int sizePacket = sizeof(packet);
		SOCKADDR_IN from;
		int fromL = sizeof(from);
		Sleep(1000);
		int receive = recvfrom(sock, (char*)packet, sizePacket, 0, (SOCKADDR*)&from, &fromL);
		if(receive < 0 ){
			cout<<"Failed recv : "<<WSAGetLastError()<<endl;
		}
		int sendBytes = sendto(sock, (const char*)msg, sizeof(msg), 0, (SOCKADDR*)&from, fromL);
		if(sendBytes != sizeof(msg)){
			cout<<"Failed sendBytes\n";
		}
		int fromPort = ntohs(from.sin_port);
		cout<<packet<<"; port:"<<fromPort<<endl;
	}
}
