#pragma once
#include <iostream>
#include"Simulator .h"
#include"Buffer.h"
#include "random.h"
#include "DiscoverMessage.h"
static int idCamera = 0;
class Camera {
	char cameraId;
	
	BaseMessage ** messages;
	Buffer * buffer;
	int indexOfMessage;
public:
Camera();
bool isActive;
void generate();
void sendToBuffer();
void run();
void stop();
void send();
};