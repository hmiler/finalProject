#pragma once
#include <iostream>
class Buffer {

	char ** buffer = (char**)malloc(1);
	int index = 1;


public:
	void addToBuffer(char * message);
	char ** getBuffer();
	void cleanBuffer();
};