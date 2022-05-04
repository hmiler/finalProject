#pragma once
#include <iostream>
#include<cstring>

#ifndef BaseMessage
#define baseMessage
class BaseMessage {
protected:
	unsigned char* messageBuffer;
	int messageId;
	int messageType;
public:
	BaseMessage(unsigned char* buffer, int id);

	BaseMessage(int type, int id);

	BaseMessage();
	virtual void parseMessage() = 0;
	virtual void parseBack() = 0;
	virtual void print() = 0;
	unsigned char* getMessageBuffer();
};
#endif