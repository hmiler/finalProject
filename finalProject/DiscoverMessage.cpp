#include "DiscoverMessage.h"

DiscoverMessage::DiscoverMessage(unsigned char* buffer, int id):BaseMessage(buffer,id)  {
		distance = 0;
		angle = 0;
		speed = 0;
	}

DiscoverMessage::DiscoverMessage(float distance, float angle, float speed, int id) :BaseMessage(1, id) {
		distance = distance;
		angle = angle;
		speed = speed;
	}

	 void DiscoverMessage::parseMessage() {
		memcpy((void*)(&distance), (void*)(messageBuffer[2]), 4);
		memcpy((void*)(&angle), (void*)(messageBuffer[6]), 4);
		memcpy((void*)(&speed), (void*)(messageBuffer[10]), 4);
	}

	 void DiscoverMessage::parseBack() {
		messageBuffer = new unsigned char[3];
		memcpy((void*)(messageBuffer), (void*)(&messageType), 2);
		memcpy((void*)(messageBuffer + 2), (void*)(&distance), 4);
		memcpy((void*)(messageBuffer + 6), (void*)(&angle), 4);
		memcpy((void*)(messageBuffer + 10), (void*)(&speed), 4);
	}

	 void DiscoverMessage::print() {
		cout << "distance:  " << distance << endl
			<< "angle:  " << angle << endl
			<< "speed:  " << speed << endl;
	}

