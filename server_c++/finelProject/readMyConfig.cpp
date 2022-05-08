#include "readMyConfig.h"

using namespace std;
int numofcameras;
int ms;
void read() {
	fstream newfile;
	newfile.open("config.txt", ios::in); //open a file to perform read operation using file object
	if (newfile.is_open()) { //checking whether the file is open
		string tp;
		getline(newfile, tp); //read data from file object and put it into string.
		int indexStart = tp.find(':');
		int indexStop = tp.find('.');
		tp = tp.substr(indexStart + 1, indexStop - indexStart - 1);
		numofcameras = 0;
		numofcameras = (int)(stoi(tp));

		getline(newfile, tp); //read data from file object and put it into string.
		indexStart = tp.find(':');
		indexStop = tp.find('.');
		tp = tp.substr(indexStart + 1, indexStop - indexStart - 1);
		ms = 0;
		ms = (int)(stoi(tp));

		cout << "tp" << tp << "\n"; //print the data of the string
		newfile.close(); //close the file object.
	}
}
int return_time_in_ms() {
	read();
	return ms;
}
int return_num_of_camera() {
	read();
	return numofcameras;
}