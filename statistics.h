#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class stats
{
public:
	stats(string mode, string memMode) : algo(mode), memAlgo(memMode) {
		cpuBurstTimeTotal = 0;
		cpuBurstTimeCount = 0;
		cpuBurstTimeAverage = 0.0;
		waitTimeTotal = 0;
		waitTimeCount = 0;
		waitTimeAverage = 0.0;
		turnAroundTimeTotal = 0;
		turnAroundTimeCount = 0;
		turnAroundtimeAverage = 0.0;
		defragTimeTotal = 0;
		defragTimeCount = 0;
		defragTimeAverage = 0.0;
		endTime = 0;
		contextSwitch = 0;
	}



	~stats();

	void Reset(string mode, string memMode) {
		algo = mode;
		memAlgo = memMode;

		cpuBurstTimeTotal = 0;
		cpuBurstTimeCount = 0;
		cpuBurstTimeAverage = 0.0;
		waitTimeTotal = 0;
		waitTimeCount = 0;
		waitTimeAverage = 0.0;
		turnAroundTimeTotal = 0;
		turnAroundTimeCount = 0;
		turnAroundtimeAverage = 0.0;
		defragTimeTotal = 0;
		defragTimeCount = 0;
		defragTimeAverage = 0.0;
		endTime = 0;
		contextSwitch = 0;
	}

	void AddCpuTime(int time, int occurance) {
		cpuBurstTimeTotal += time*occurance;
		cpuBurstTimeCount += occurance;
		cpuBurstTimeAverage = (float)cpuBurstTimeTotal / cpuBurstTimeCount;
	}

	void AddWaitTime(int time) {
		waitTimeTotal += time;
		++waitTimeCount;
		waitTimeAverage = (float)waitTimeTotal / waitTimeCount;
	}

	void AddTurnAroundTime(int time) {
		turnAroundTimeTotal += time;
		++turnAroundTimeCount;
		turnAroundtimeAverage = (float)turnAroundTimeTotal / turnAroundTimeCount;
	}

	void AddDefragTime(int time) {
		defragTimeTotal += time;
		++defragTimeCount;
	}

	void Print(ofstream& output) {
		output << "Algorithm " << algo << " and " << memAlgo << endl;
		output << " -- average CPU burst time: " << cpuBurstTimeAverage << " ms" << endl;
		output << " -- average wait time: " << waitTimeAverage << " ms" << endl;
		output << " -- average turnaround time: " << turnAroundtimeAverage << " ms" << endl;
		output << " -- total number of context switches: " << contextSwitch << endl;
		output << " -- total time spend defragmenting: " << defragTimeTotal << " ms" << endl;
	}


	string algo;
	string memAlgo;

	int cpuBurstTimeTotal;
	int cpuBurstTimeCount;
	float cpuBurstTimeAverage;

	int waitTimeTotal;
	int waitTimeCount;
	float waitTimeAverage;

	int turnAroundTimeTotal;
	int turnAroundTimeCount;
	float turnAroundtimeAverage;

	int defragTimeTotal;
	int defragTimeCount;
	float defragTimeAverage;

	int endTime;
	int contextSwitch;


};