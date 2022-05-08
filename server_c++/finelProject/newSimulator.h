//#pragma once

#include <mutex>
#include <thread>
#include <iostream>
#include"Camera.h"
#include <vector>
#include "readMyConfig.h"
#include "sendToServer.h"
#ifndef generalSIMULATOR
#define generalSIMULATOR
using namespace std::literals::chrono_literals;


using namespace std;
#include "Camera.h"
class newSimulator
{
	
public:

  void running();
  Camera ** cameraArr;
  thread* sendThreadsArr;
  thread* runThreadsArr;
  thread* stopThreadArr;
	void sendServer(Camera* c);
	~newSimulator();
	newSimulator();

};
#endif 









