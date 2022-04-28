
//#include "Simulator .h"
//
//
//
//void Simulator::creatDiscoveryMessage(float distance, float angle, float speed) {
//	buffer = (BaseMessage**)realloc(buffer, index * sizeof(BaseMessage*));
//	buffer[index - 1] = new discoveryMessage(distance, angle, speed, index);
//	index++;
//}
//
//void Simulator::creatStatusMessage() {
//	buffer = (BaseMessage**)realloc(buffer, index * sizeof(BaseMessage*));
//	buffer[index - 1] = new statusMessage(index);
//	index++;
//}
//
//Simulator::~Simulator() {
//	for (int i = 0; i < index; i++) {
//		delete(buffer + i);
//	}
//	delete[] buffer;
//}
//unsigned char *Simulator::generteAndSendMessage(int i) {
//	buffer[i]->print();
//	buffer[i]->parseBack();
//	buffer[i]->print();
//	return buffer[i]->getMessageBuffer();
//
//}
//
//
