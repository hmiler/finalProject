#include "Buffer.h"

Buffer::Buffer() {
	buffer = (char**)malloc(sizeof(char*));
	index = 1;
}

void Buffer::addToBuffer(char * message) {
	m.lock();
	char ** tmpbuffer = (char **)(realloc(buffer, index * sizeof(char *)));
	if (tmpbuffer != NULL) {
		buffer = tmpbuffer;
		buffer[index - 1] = message;
	}
	
	index++;
	m.unlock();
}
char ** Buffer::getBuffer() {
	m.lock();
	char** tmp = buffer;
	return tmp;
	m.unlock();
}
void Buffer::cleanBuffer() {
	m.lock();

	buffer = (char**)malloc(sizeof(char*));
	index = 1; 
	m.unlock();
}
