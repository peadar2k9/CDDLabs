/*! 
\author Peter Cronin
\date 12/10/2017
\email peadarcronin1@gmail.com
\file Semaphore.cpp
\brief Semaphore class
\license GNU (General Public License)
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>

int size = 20;

void taskOne(std::shared_ptr<Semaphore> aArrived, std::shared_ptr<Semaphore> bArrived, int threadNum){
  std::cout <<"Thread " + std::to_string(threadNum) + " arrived & waiting" << std::endl;  
  aArrived->Wait();
  std::cout << "Thread " + std::to_string(threadNum) + " released" <<std::endl;
  Arrived->Signal();
}

void taskTwo(std::shared_ptr<Semaphore> aArrived, std::shared_ptr<Semaphore> bArrived, int threadNum){
  std::cout <<"Thread " + std::to_string(threadNum) + " arrived & signalling" << std::endl;  
  aArrived->Wait();
  bArrived -> Wait();
  std::cout << "Thread " + std::to_string(threadNum) + " goes next" <<std::endl;
}

void startVector(std::vector<std::thread> &threads, std::shared_ptr<Semaphore> aArrived, std::shared_ptr<Semaphore> bArrived){
    for (int i = 0; i < size; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
        if (i < 5){
            std::thread current_thread = std::thread(taskOne, aArrived, bArrived, i);
            threads.push_back(move(current_thread));
        }else{
            std::thread current_thread = std::thread(taskTwo, aArrived, bArrived, i);
            threads.push_back(move(current_thread));
        }
    }
}

int main(void){
  std::shared_ptr<Semaphore> aArrived( new Semaphore);
  std::shared_ptr<Semaphore> bArrived( new Semaphore);
  std::vector<std::thread> threads;
  startVector(threads,aArrived, bArrived);
  for(std::thread &thread: threads){
    thread.join();
  }
  return 0;
}
