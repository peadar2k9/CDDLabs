/*! 
\author Peter Cronin
\date 06/11/2017
\email peadarcronin1@gmail.com
\file Barrier.h
\brief Reusable Barrier header file
\license GNU (General Public License)
*/

#include <mutex>
#include <condition_variable>
#include <chrono>
#include "Semaphore.h"

class barrier{
public:
	int count;
	int n;
	int threads;
	std::shared_ptr<Semaphore> mutex;
	std::shared_ptr<Semaphore> turnstile1;
	std::shared_ptr<Semaphore> turnstile2;
	void PartOne();
	void PartTwo();
	barrier(int count);
	void Wait();
};