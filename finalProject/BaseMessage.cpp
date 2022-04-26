
#include "BaseMessage.h"


BaseMessage::BaseMessage(unsigned char* buffer, int id) {
	this->messageBuffer = buffer;
	this->messageId = id;
	messageType = static_cast<int>(messageBuffer[1]);
}

BaseMessage::BaseMessage(int type, int id) {
	this->messageBuffer = 0;
	this->messageId = id;
	messageType = type;
}

BaseMessage::~BaseMessage() {
	delete[]messageBuffer;
}

unsigned char* BaseMessage::getMessageBuffer() {
	return messageBuffer;
}


