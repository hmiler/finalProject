#include "newSimulator.h"

Camera arrCamera[sumCamera];

void newSimulator::sendServer(Camera * c) {
	while (true) {
		while (c->isActive)
		{
		c->send();
		for (int j = 0; j < timems; j++)
		{
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
	thread* threadRun = new thread[sumCamera];
	thread* threadStop = new thread[sumCamera];
	thread* sendThreadArr = new thread[sumCamera];
	/*std::vector<thread> threadRun(sumCamera);
	std::vector<thread> threadStop(sumCamera);
	std::vector< thread> sendThreadArr(sumCamera);*/

	for (int i = 0; i < sumCamera; i++) {
		sendThreadArr[i] = thread(&newSimulator::sendServer, this, &arrCamera[i]);
		threadRun[i] = thread(&Camera::run, &arrCamera[i]);


	}
	for (int j = 0; j < sumCamera; j++) {
		getchar();
		threadStop[j] = thread(&Camera::stop, &arrCamera[j]);

	}
	for (int x = 0; x < sumCamera; x++) {
		threadRun[x].join();
		sendThreadArr[x].join();
		threadStop[x].join();
	}
}



