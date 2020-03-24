#pragma once

#include <list>
#include <mutex>

class WorkQueue
{

public:

	WorkQueue();

	void push(int n);
	int pop();
	int size();


private:
	std::mutex mtx;
	std::list<int> jobs;

};

