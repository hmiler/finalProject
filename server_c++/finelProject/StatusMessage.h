#pragma once
#include <iostream>
#include "BaseMessage.h"
using namespace std;
class statusMessage :public BaseMessage {
protected:
	short status;
public:
	statusMessage(unsigned char* buffer, int id);
	statusMessage(int id, short stat);

	virtual void parseMessage();

	virtual void parseBack();

	virtual void print();

};