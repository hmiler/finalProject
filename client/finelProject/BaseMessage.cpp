
#include "BaseMessage.h"


BaseMessage::BaseMessage(unsigned char* buffer, int id) {
	this->messageBuffer = buffer;
	this->messageId = id;
	messageType = static_cast<int>(buffer[1]);
}

BaseMessage::BaseMessage(int type, int id) {
	this->messageBuffer = NULL;
	this->messageId = id;
	messageType = type;
}

BaseMessage::BaseMessage() {
	messageBuffer = NULL;
	messageId = 0;
	messageType = 0;
}

unsigned char* BaseMessage::getMessageBuffer() {
	return messageBuffer;
}


