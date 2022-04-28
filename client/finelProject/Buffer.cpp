#include "Buffer.h"



void Buffer::addToBuffer(char * message) {
	buffer = (char **)(realloc(buffer, index * sizeof(char *)));
	buffer[index - 1] = message;
	index++;
}
char ** Buffer::getBuffer() {
	return buffer;
}
void Buffer::cleanBuffer() {
	free(buffer);
	buffer = NULL;
	index = 0;
}
