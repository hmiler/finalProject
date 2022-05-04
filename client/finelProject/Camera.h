#pragma once
#ifndef CAMERA
#define _WINSOCK_DEPRECATED_NO_WARNINGS
#define CAMERA
#include <iostream>
#include"Simulator .h"
#include"Buffer.h"
#include "random.h"
#include "DiscoverMessage.h"
#include "BaseMessage.h"
#include "StatusMessage.h"
static int idCamera = 0;
#pragma comment (lib, "Ws2_32.lib")
#include <iostream>
#include <string.h>
#include <sstream>
#include <WinSock2.h>
#include <WS2tcpip.h>

using namespace std;
class Camera {
	char cameraId;
	
	BaseMessage ** messages;
	
	int indexOfMessage;
public:
	Buffer* buf;
	SOCKET connection;
Camera();
~Camera();
bool isActive;
void generate();
void sendToBuffer();
void run();
void stop();
void sendServer();
};
#endif 