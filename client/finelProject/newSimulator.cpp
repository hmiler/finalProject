#include "newSimulator.h"
newSimulator::~newSimulator() {
	delete[]stopThreadArr;
	delete[]runThreadsArr;
	delete[]sendThreadsArr;
}

newSimulator::newSimulator() {
	sendThreadsArr = new thread[sumCamera];
	runThreadsArr = new thread[sumCamera];
	stopThreadArr = new thread[sumCamera];
}
//Camera arrCamera[sumCamera];

void newSimulator::sendServer(Camera * c) {
	while (true) {
		while (c->isActive)
		{
		
		for (int j = 0; j < c->buf->index; j++)
		{
			c->sendServer(/*c->buf->buffer[j]*/);
			std::this_thread::sleep_for(1s);
		}
		}
	}
}

//void newSimulator::runSimulator(int i) {
//	arrCamera[i].run();
//}
//
//void newSimulator::stopSimulator(int i) {
//	arrCamera[i].stop();
//}

void newSimulator::running()
{
	
	/*std::vector<thread> threadRun(sumCamera);
	std::vector<thread> threadStop(sumCamera);
	std::vector< thread> sendThreadArr(sumCamera);*/

	for (int i = 0; i < sumCamera; i++) {
		runThreadsArr[i] = thread(&Camera::run, &cameraArr[i]);
		sendThreadsArr[i] = thread(&newSimulator::sendServer, this, &cameraArr[i]);

	}
	for (int j = 0; j < sumCamera; j++) {
		getchar();
		stopThreadArr[j] = thread(&Camera::stop, &cameraArr[j]);

	}
	/*for (int x = 0; x < sumCamera; x++) {
		threadRun[x].join();
		sendThreadArr[x].join();
		threadStop[x].join();
	}*/
}



