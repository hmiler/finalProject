#include "newSimulator.h"
int num_of_camera = return_num_of_camera();
int timeMs=return_time_in_ms();


newSimulator::newSimulator() {
	this->cameraArr = (Camera**)(malloc(num_of_camera * sizeof(Camera)));
	for (int i = 0; i < num_of_camera; i++) {
		cameraArr[i] = new Camera('a' + i);
	}
	std::thread tf(&newSimulator::running, this);
	start();
	tf.join();
}
void newSimulator::sendServer(Camera* c) {
	while (c->isActive)
	{
		for (int k = 0; k < timeMs; k++)
		{
			std::this_thread::sleep_for(1s);
			send(c->sendBufferToServer()->getBuffer(), c->sendBufferToServer()->index);
			c->sendBufferToServer()->cleanBuffer();
		}
		
	}
}


void newSimulator::running()
{
	sendThreadsArr=new thread[num_of_camera];
	runThreadsArr = new thread[num_of_camera];
 stopThreadArr = new thread[num_of_camera];
	/*std::vector<thread> threadRun(sumCamera);
	std::vector<thread> threadStop(sumCamera);
	std::vector< thread> sendThreadArr(sumCamera);*/

	for (int i = 0; i < num_of_camera; i++) {
		runThreadsArr[i] = thread(&Camera::run,cameraArr[i]);
		sendThreadsArr[i] = thread(&newSimulator::sendServer, this, cameraArr[i]);

	}
	for (int j = 0; j < num_of_camera; j++) {
		getchar();
		stopThreadArr[j] = thread(&Camera::stop, cameraArr[j]);

	}
	for (int x = 0; x < num_of_camera; x++) {
		sendThreadsArr[x].join();
		runThreadsArr[x].join();
		stopThreadArr[x].join();
	}
}
newSimulator::~newSimulator() {
	for (int i = 0; i < num_of_camera; i++) {
		delete cameraArr[i];
	}
	free(cameraArr);

}


