#pragma once
#include <iostream>
#include<mutex>
class Buffer {

	


public:
	std::mutex m;
	char ** buffer ;
	Buffer();
	int index = 1;
	void addToBuffer(char * message);
	char ** getBuffer();
	void cleanBuffer();
};