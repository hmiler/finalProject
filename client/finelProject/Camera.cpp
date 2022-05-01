#include "Camera.h"


Camera::Camera() {
	this->messages =(BaseMessage**)malloc(sizeof(BaseMessage*));
		this->cameraId = ++idCamera;
		this->isActive = true;
		indexOfMessage = 0;
	}
Camera::~Camera() {
	for (int i = 0; i < indexOfMessage; i++) {
		free(messages[i]);
	}
	messages = NULL;
}

void Camera::generate() {
	int count = getProb(1, 6);
	//std::cout << "generate camera id= " << id <<", count "<<count<< '\n';
	while (count--) {
		int id = indexOfMessage + 1;
		float distance = getProb(500, 10000);
		float angle = getProb(0, 360);
		float speed = getProb(0, 1000);
		BaseMessage* newMessage = new DiscoverMessage(id, distance, angle, speed);
		std::cout << "index is " << indexOfMessage << '\n';
		BaseMessage** tmpMassages = (BaseMessage**)realloc(messages, sizeof(BaseMessage*)*(indexOfMessage + 1));
		int cnt = 0;
		while (tmpMassages == NULL) {
			sendToBuffer();
			tmpMassages = (BaseMessage**)realloc(messages, sizeof(BaseMessage*) * (indexOfMessage + 1));
			if (cnt++ == 3) {
				std::cout << "I didn't have place of memory, sory!" << '\n';
				stop();
			}
		}
		std::cout << newMessage << count << '\n';
		messages = tmpMassages;
		messages[indexOfMessage] = newMessage;
		std::cout << " messages is " ;
		messages[indexOfMessage]->print();
		indexOfMessage++;
	}
}

void Camera::sendToBuffer() {
		for (int j = 0; j < indexOfMessage; j++)
		{
			messages[j]->parseBack();
			buffer->addToBuffer( reinterpret_cast<char*>( messages[j]->getMessageBuffer()));
		
		}
		free(messages);
		messages = NULL;
		indexOfMessage = 0;
	}
	void Camera::run() {
		while (isActive)
			generate();
		if (isActive)
			sendToBuffer();
	}
	void Camera::stop() {
		isActive = false;
	}
	void Camera::send() {
		
	}
