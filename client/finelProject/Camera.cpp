#include "Camera.h"


Camera::Camera() {
	this->messages =(BaseMessage**)malloc(sizeof(BaseMessage*));
		this->cameraId = ++idCamera;
		this->isActive = true;
		indexOfMessage = 0;
		this->buf = new Buffer();
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
		
		int type = getProb(1, 3);
		BaseMessage* newMessage;
		if (type == 2) {
			float distance = getProb(500, 10000);
			float angle = getProb(0, 360);
			float speed = getProb(0, 1000);
			newMessage = new DiscoverMessage(id, distance, angle, speed);
		}
		else {
			short stat = getProb(1, 5);
			newMessage = new statusMessage(id, stat);
		}std::cout << "index is " << indexOfMessage << '\n';
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
			buf->addToBuffer( reinterpret_cast<char*>( messages[j]->getMessageBuffer()));
		
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
		closesocket(this->connection);
		WSACleanup();
	}
	void Camera::sendServer() {
		//
		//this->buf->m.lock();
		//WSAData wsaData;
		//WORD DllVersion = MAKEWORD(2, 1);
		//if (WSAStartup(DllVersion, &wsaData) != 0) {
		//	cout << "Winsock Connection Failed!" << endl;
		//	exit(1);
		//}

		//string getInput = "";
		//SOCKADDR_IN addr;
		//int addrLen = sizeof(addr);
		//IN_ADDR ipvalue;
		//addr.sin_addr.s_addr = inet_addr("127.0.0.1");
		//addr.sin_port = htons(80);
		//addr.sin_family = AF_INET;

		//this->connection = socket(AF_INET, SOCK_STREAM, NULL);
		//if (connect(this->connection, (SOCKADDR*)&addr, addrLen) == 0) {
		//	cout << "Connected!" << endl;
		//	//cout << "sin_addr.S_un: " << addr.sin_addr.S_un << endl;

		//	//getline(cin, getInput);
		//	//send(connection, "pshshhshs", 2, 0);
		//	/*for (int k = 0; k < this->buf->i; k++)
		//	{

		//	}*/

		//	send(this->connection, *(this->buf->buffer), 14, 0);
		//	cout << "Buffer sent!" << endl;
		//	this->buf->m.unlock();
		//	this->buf->cleanBuffer();

		//	Sleep(1);
		//	/*closesocket(connection);
		//	WSACleanup();*/
		//	cout << "Socket closed." << endl << endl;
		//	//exit(0);
		//	std::cout << "camera number: " << (this->cameraId) << "  send . . . ";
		//	for (int i = 0; i < indexOfMessage; i++)
		//	{

		//		
		//	}
		//}
		//else {
		//	cout << "Error Connecting to Host" << endl;
		//	return;
		//	//exit(1);
		//}

	}


	