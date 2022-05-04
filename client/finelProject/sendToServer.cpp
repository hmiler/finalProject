#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment (lib, "Ws2_32.lib")
#include <iostream>
#include <string.h>
#include <sstream>
#include <WinSock2.h>
#include <WS2tcpip.h>
#include"sendToServer.h"
using namespace std;
SOCKET connection;
void start() {
	WSAData wsaData;
	WORD DllVersion = MAKEWORD(2, 1);
	if (WSAStartup(DllVersion, &wsaData) != 0) {
		cout << "Winsock Connection Failed!" << endl;
		exit(1);
	}

	string getInput = "";
	SOCKADDR_IN addr;
	int addrLen = sizeof(addr);
	IN_ADDR ipvalue;
	addr.sin_addr.s_addr = inet_addr("127.0.0.1");
	addr.sin_port = htons(81);
	addr.sin_family = AF_INET;

	connection = socket(AF_INET, SOCK_STREAM, NULL);
	if (connect(connection, (SOCKADDR*)&addr, addrLen) == 0) {
		cout << "Connected!" << endl;
		//getline(cin, getInput);
		char x;
		//cin >> x;
	}
	else {
		cout << "Error Connecting to Host" << endl;
		exit(1);
	}
}
void send(char** buf, int len) {
	for (int i = 0; i < len - 1; i++) {
		if (buf[i][0] == 1)
			send(connection, buf[i], 6, 0);
		if (buf[i][0] == 2)
			send(connection, buf[i], 14, 0);
	}
	//send(connection, "5ddddd", 5, 0);
	cout << "Message sent!" << endl;

}
void finish() {
	closesocket(connection);
	//
	WSACleanup();

	//cin >> x;
	cout << "Socket closed." << endl << endl;
}