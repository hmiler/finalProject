#include "statusMessage.h"

statusMessage::statusMessage(unsigned char* buffer, int id) :BaseMessage(buffer, id) {
		status = 0;
	}

statusMessage::statusMessage(int id) :BaseMessage(1, id) {
		status = 0;
	}

 void statusMessage::parseMessage() {
		status = static_cast<short>(messageBuffer[2]);
	}

	 void statusMessage::parseBack() {
		this->messageBuffer = new unsigned char[3];
		memcpy((void*)(messageBuffer), (void*)(&messageType), 2);
		memcpy((void*)(messageBuffer + 2), (void*)(&status), 1);
	}

	 void statusMessage::print() {
		cout << "\tstatus:  " << status << endl;
	}


