#include "Buffer.h"



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
	return buffer;
}
void Buffer::cleanBuffer() {
	free(buffer);
	buffer = NULL;
	index = 0;
}
