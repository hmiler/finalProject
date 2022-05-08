#include "Buffer.h"

Buffer::Buffer() {
	buffer = (char**)malloc(sizeof(char*));
	index = 1;
}
Buffer::~Buffer() {
	free(buffer);
};

void Buffer::addToBuffer(char * message) {
	m.lock();
	buffer = (char**)(realloc(buffer, this->index * sizeof(char*)));
	buffer[index - 1] = message;
	index++;
	m.unlock();
}
char ** Buffer::getBuffer() {
	return buffer;
}
void Buffer::cleanBuffer() {
	m.lock();
	free(buffer);
	buffer = (char**)malloc(sizeof(char*));
	index = 1; 
	m.unlock();
}
