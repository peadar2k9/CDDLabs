/*! 
\author Peter Cronin
\date 06/11/2017
\email peadarcronin1@gmail.com
\file main.cpp
\brief Reusable Barrier main file
\license GNU (General Public License)
*/

#include "Barrier.h"
#include <iostream>
#include <thread>
#include <mutex>
#include <vector>

/*!
\fn void taskOne(std::shared_ptr<barrier> reBarrier, int n)
\brief Function that lets multiple threads enter
\param barriers reBarrier, n
*/

void taskOne(std::shared_ptr<barrier> reBarrier, int n){
    std::cout << "Thread " << n << " in first turnstile" << std::endl;
    reBarrier->PartOne();
    std::cout << "Thread " << n << " in second turnstile" << std::endl;
    reBarrier->PartTwo();
}

/*!
\fn int main()
\brief Main function
*/

int main(void){
    int n = 8;
    std::thread allThreads[n];
    std::shared_ptr<barrier> reBarrier(new barrier(n));
    /**< Launches the threads  */
    for(int i = 0; i < n; i++){
        allThreads[i] = std::thread(taskOne, reBarrier, i);
    }
    for(int i = 0; i < n; i++){
        allThreads[i].join();
    }
    std::cout << "Threads finished." << std::endl;
    return 0;
}