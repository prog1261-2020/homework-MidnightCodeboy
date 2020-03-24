/**
* @file ProducersAndConsumers.cpp
*
* @author  Joseph Roy-Plommer
* @version <1.0>
* @date 2020-03-24
*
* @section Academic Integrity
*  I certify that this work is solely my own and complies with
*  NBCC Academic Integrity Policy (policy 1111)
*
* @section DESCRIPTION
*	Produces a vector of jobs using multithreaded functions. Then consumes all the jobs using other threads.
*
* @section LICENSE
*  <any necessary attributions>
*
*  Copyright 2019
*  Permission to use, copy, modify, and/or distribute this software for
*  any purpose with or without fee is hereby granted, provided that the
*  above copyright notice and this permission notice appear in all copies.
*
*  THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
*  WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
*  MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
*  ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
*  WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
*  ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
*  OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
*
*/

#include "WorkQueue.h"
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <vector>
#include <atomic>
#include <mutex>
#include <chrono>


std::atomic<int> produced = 0;
std::atomic<int> consumed = 0;

std::atomic<bool> start = false;
std::atomic<bool> stop = false;

std::mutex coutMutex;

WorkQueue jobs;

// routine to run in a thread and produce ints for the work queue until thread ends.
void producer() {
	while (!start) {
		//std::this_thread::sleep_for(std::chrono::milliseconds(10));
		//coutMutex.lock();
		//std::cout << "waiting to start producing..." << std::endl;
		//coutMutex.unlock();
		std::this_thread::yield();
	}

	while (!stop) {
		jobs.push(rand() % 100);
		produced++;
		std::this_thread::sleep_for(std::chrono::microseconds(10));
	}

	return;
	
}

// routine to run in a thread and consume ints from the work queue until thread ends.
void consumer(int id) {
	while (!start) {
		std::this_thread::sleep_for(std::chrono::milliseconds(10));
	}
	while (true) {
		if (stop && jobs.size() == 0) {
			return;
		}

		int job = jobs.pop();
		consumed++;
		//std::this_thread::sleep_for(std::chrono::microseconds(10));
		coutMutex.lock();
		std::cout << "Consumer with id: " << id << " has consumed job value " << job << std::endl;
		coutMutex.unlock();
	}

}


int main() {

	srand(time(NULL));
	std::vector<std::thread> producers;
	std::vector<std::thread> consumers;

	// Create producers and add to list
	for (int i = 0; i < 10; i++) {
		producers.push_back(std::thread(producer));
	}

	// Create consumers and add to list
	for (int i = 0; i < 5; i++) {
		consumers.push_back(std::thread(consumer, i));
	}

	start = true;
	std::this_thread::sleep_for(std::chrono::milliseconds(100));
	stop = true;

	// Wait for producers to finish
	for (int i = 0; i < producers.size(); i++) {
		producers[i].join();
	}

	// Wait for consumers to finish
	for (int i = 0; i < consumers.size(); i++) {
		consumers[i].join();
	}

	// Show that everything was consumed before quitting.
	std::cout << "Produced: " << produced << std::endl;
	std::cout << "Consumed: " << consumed << std::endl;

	for (int i = 0; i < jobs.size(); i++) {
		//int n = jobs.pop();
		std::cout << " " << jobs.pop() << std::endl;
	}

	return 0;
}