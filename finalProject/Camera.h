#pragma once
#include <iostream>
#include"Simulator .h"
#include"Buffer.h"
#include "random.h"
#include "DiscoverMessage.h"
static int idCamera = 0;
class Camera {
	char cameraId;
	bool isActive;
	BaseMessage ** messages;
	Buffer * buffer;
	int indexOfMessage;
public:
Camera();
void generate();
void sendToBuffer();
void run();
void stop();
void send();
};