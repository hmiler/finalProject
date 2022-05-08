#pragma once
#ifndef CAMERA
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define CAMERA
#include <iostream>
#include"Buffer.h"
#include "random.h"
#include "DiscoverMessage.h"
#include "BaseMessage.h"
#include "StatusMessage.h"

#pragma comment (lib, "Ws2_32.lib")
#include <iostream>
#include <string.h>
#include <sstream>
#include <WinSock2.h>
#include <WS2tcpip.h>

using namespace std;
class Camera {
	
public:
	char cameraId;

	BaseMessage** messages;

	int indexOfMessage;
	Buffer* buf;
	SOCKET connection;
Camera(char id);
~Camera();
bool isActive;
Buffer* sendBufferToServer();
void print();

void generate();
void sendToBuffer();
void run();
void stop();

void sendServer();

};
#endif 