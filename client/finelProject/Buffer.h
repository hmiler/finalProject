#pragma once
#include <iostream>
#include<mutex>

#ifndef BUFFER
#define BUFFER

class Buffer {

public:
	std::mutex m;
	char ** buffer ;
	int len = 0;
	Buffer();
	~Buffer();
	int index = 1;
	void addToBuffer(char * message);
	char ** getBuffer();
	void cleanBuffer();
};

#endif 
