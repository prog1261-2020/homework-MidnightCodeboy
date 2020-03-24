#include "WorkQueue.h"

WorkQueue::WorkQueue()
{
}

void WorkQueue::push(int n)
{
	std::lock_guard<std::mutex> guard(mtx);
	jobs.push_back(n);
}

int WorkQueue::pop()
{
	while (true) {

		mtx.lock();
		// critical section
		if (jobs.size() == 0) {
			mtx.unlock();
			// end critical section

			std::this_thread::yield();
		}
		// critical section
		else {
			int r = jobs.front();
			jobs.pop_front();
			mtx.unlock();
			// end critical section

			return r;
		}
	}
}

int WorkQueue::size()
{
	std::lock_guard<std::mutex> guard(mtx);
	return jobs.size();
}
