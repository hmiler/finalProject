//#pragma once

#include <mutex>
#include <thread>
#include <iostream>
#include"Camera.h"
#include <vector>
#ifndef generalSIMULATOR
#define generalSIMULATOR
using namespace std::literals::chrono_literals;
const int timems=2;

using namespace std;
#include "Camera.h"
class newSimulator
{
	
public:
	const int sumCamera = 10;
  void running();
  Camera* cameraArr = new Camera[sumCamera];
  thread* sendThreadsArr;
  thread* runThreadsArr;
  thread* stopThreadArr;
	void sendServer(Camera* c);
	~newSimulator();
	newSimulator();

};
#endif 









