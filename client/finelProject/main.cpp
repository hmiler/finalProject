//
//#include "newSimulator.h"
//int main()
//{
//
//	newSimulator s;
//	s.running();
//
//}
//#include "stdafx.h"
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#pragma comment (lib, "Ws2_32.lib")
#include <iostream>
#include <string.h>
#include <sstream>
#include <WinSock2.h>
#include <WS2tcpip.h>
using namespace std;


int main()
{
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
	addr.sin_port = htons(80);
	addr.sin_family = AF_INET;
	
	SOCKET connection = socket(AF_INET, SOCK_STREAM, NULL);
	string buffer = "hello ";
	if (connect(connection, (SOCKADDR*)&addr, addrLen) == 0) {
		cout << "Connected!" << endl;
		send(connection, buffer.c_str(), buffer.length(), 0);
		closesocket(connection);
		/*WSACleanup();*/
		getline(cin, getInput);
		exit(0);
	}
	else {
		cout << "Error Connecting to Host" << endl;
		exit(1);
	}
	getchar();
	return 0;
}