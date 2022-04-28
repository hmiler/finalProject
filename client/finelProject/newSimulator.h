//#pragma once

#include <mutex>
#include <thread>
#include <iostream>
#include"Camera.h"
#include <vector>
using namespace std::literals::chrono_literals;
const int timems=2;
const int sumCamera = 10;
using namespace std;
#include "Camera.h"
class newSimulator
{
	
public:
	
  void running();
	/*void runSimulator(int i);*/
	/*void stopSimulator(int i);*/
	void sendServer(Camera* c);

};










