//#include "newSimulator.h"
//
//void newSimulator::runSimulator(int i) {
//	arrCamera[i].run();
//}
//void newSimulator::stopSimulator(int i) {
//	arrCamera[i].stop();
//
//}
//void newSimulator::runing() {
//	std::vector< std::thread> sendThreadArr(sumCamera);
//	std::vector < std::thread>runThreadArr(sumCamera);
//	std::vector < std::thread>stopThreadArr(sumCamera);
//	for (int i = 0; i < sumCamera; i++)
//	{
//		sendThreadArr[i] = std::thread(&newSimulator::sendServer, i);
//		sendThreadArr[i] = std::thread(&newSimulator::runSimulator, i);
//
//
//	}
//	for (int j = 0; j < sumCamera; j++)
//	{
//		getchar();
//		//sendThreadArr[j] = std::thread(&newSimulator::stopSimulator, j);
//	}
//}
//
//void newSimulator::sendServer(int i) {
//	while (true) {
//		arrCamera[i].send();
//		for (int j = 0; j < timems; j++)
//		{
//			std::this_thread::sleep_for(1s);
//		}
//	}
//}
//
#include <thread>
#include <iostream>
#include"Camera.h"
const int sumCamera = 10;
#include <vector>
Camera arrCamera[sumCamera];
using namespace std;

void runSimulator(int i) {
	arrCamera[i].run();
}
void stopSimulator(int i) {
	arrCamera[i].stop();

}
/**
 * Spawns n threads
 */
void spawnThreads(int n)
{
	std::vector<thread> threads(n);
	// spawn n threads:
	for (int i = 0; i < n; i++) {
		threads[i] = thread(runSimulator, i + 1);
		threads[i] = thread(stopSimulator, i + 1);
	}

	for (auto& th : threads) {
		th.join();
	}
}

int main()
{
	spawnThreads(10);
	getchar();
}
