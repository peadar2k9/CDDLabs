/*! 
\author Peter Cronin
\date 06/11/2017
\email peadarcronin1@gmail.com
\file Barrier.cpp
\brief Reusable Barrier implementation
\license GNU (General Public License)
*/
#include "Barrier.h"
#include <iostream>
#include <thread>

/*!
\fn void barrier::PartOne()
\brief First turnstile of the barrier
*/

void barrier::PartOne(){
    mutex->Wait();
    count += 1;
    if (count == n) {
        turnstile2->Wait();
        turnstile1->Signal();
    }
    mutex->Signal();
    turnstile1->Wait();
    std::cout << "Turnstile 1 Passed" << std::endl;
    turnstile1->Signal();
}

/*!
\fn void barrier::PartTwo()
\brief Second turnstile of the barrier
*/

void barrier::PartTwo(){
    mutex->Wait();
    count -= 1;
    if (count == 0) {
        turnstile1->Wait();
        turnstile2->Signal();
    }
    mutex->Signal();
    turnstile2->Wait();
    std::cout << "Turnstile 2 Passed" << std::endl;
    turnstile2->Signal();
}

void barrier::Wait(){
    PartOne();
    PartTwo();
}

barrier::barrier(int count){
    n = count;
    this->count = 0;
    mutex=std::make_shared<Semaphore>(1);
    turnstile1=std::make_shared<Semaphore>(0);
    turnstile2=std::make_shared<Semaphore>(1);
}