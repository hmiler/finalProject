#pragma once
#include <iostream>
#include "BaseMessage.h"
using namespace std;

class DiscoverMessage :public BaseMessage {
protected:
	float distance;
	float angle;
	float speed;

public:
	DiscoverMessage(unsigned char* buffer, int id) ;

	DiscoverMessage(float distance, float angle, float speed, int id) ;

	virtual void parseMessage();

	virtual void parseBack();

	virtual void print();
};