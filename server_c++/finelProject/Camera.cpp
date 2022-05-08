#include "Camera.h"


Camera::Camera(char id) {
	this->messages =(BaseMessage**)malloc(10*sizeof(BaseMessage*));
		this->cameraId =id;
		this->isActive = true;
		indexOfMessage = 0;
		this->buf = new Buffer();
	}
Camera::~Camera() {
	for (int i = 0; i < indexOfMessage; i++) {
		delete(messages[i]);
	}
	free(messages);
	delete buf;
}

void Camera::generate() {

	if (indexOfMessage >= 10) {
		messages = (BaseMessage**)(realloc((void*)messages, (indexOfMessage + 1) * sizeof(BaseMessage)));
	}

	int type = getProb(1, 3);

	if (type == 2) {
		float distance = getProb(500, 10000);
		std::cout << "distance" << distance << '\n';
		float angle = getProb(0, 360);
		std::cout << "angle" << angle << '\n';

		float speed = getProb(0, 1000);
		std::cout << "speed" << speed << '\n';

		messages[indexOfMessage] = new DiscoverMessage(type, distance, angle, speed);
	}
	else {
		short stat = getProb(1, 5);
		messages[indexOfMessage] = new statusMessage(type, stat);
	}std::cout << "index is " << indexOfMessage << '\n';
	indexOfMessage++;

}

void Camera::sendToBuffer() {
		for (int j = 0; j < indexOfMessage; j++)
		{
			messages[j]->parseBack();
			buf->addToBuffer( reinterpret_cast<char*>( messages[j]->getMessageBuffer()));
			delete messages[j];
		}
		
		indexOfMessage = 0;
	}
void Camera::run() {
	int i = 1;
	while (isActive) {
		
		if (i++ % 5 == 0) {
			sendToBuffer();
		}
		else {
			generate();
		}
	}
}
	void Camera::stop() {
		isActive = false;
		
	}
	Buffer* Camera::sendBufferToServer() {
		
		return buf;
	}

	