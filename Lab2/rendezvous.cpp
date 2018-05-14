/*! 
\author Peter Cronin
\date 13/10/2017
\email peadarcronin1@gmail.com
\file rendezvous.cpp
\brief Rendezvous implementation
\license GNU (General Public License)
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <vector>

int size = 8;

/*!
\fn void taskOne(std::shared_ptr<Semaphore> aArrived, std::shared_ptr<Semaphore> bArrived, int threadNum)
\brief Function to be called by first thread
\param barriers aArrived and bArrived passed in
*/

void taskOne(std::shared_ptr<Semaphore> aArrived, std::shared_ptr<Semaphore> bArrived, int threadNum){
  std::cout << "Thread " + std::to_string(threadNum) + " arrived & waiting" << std::endl;  
  aArrived -> Wait();
  std::cout << "Thread " + std::to_string(threadNum) + " released" << std::endl;
  bArrived -> Signal();
}

/*!
\fn void taskTwo(std::shared_ptr<Semaphore> aArrived, std::shared_ptr<Semaphore> bArrived, int threadNum)
\brief Function to be called by second thread
\param barriers aArrived and bArrived passed in
*/

void taskTwo(std::shared_ptr<Semaphore> aArrived, std::shared_ptr<Semaphore> bArrived, int threadNum){
  std::cout << "Thread " + std::to_string(threadNum) + " arrived & signalling" << std::endl;  
  aArrived -> Signal();
  bArrived -> Wait();
  std::cout << "Thread " + std::to_string(threadNum) + " goes next" << std::endl;
}

/*!
\fn void startVector(std::vector<std::thread> &threads, std::shared_ptr<Semaphore> aArrived, std::shared_ptr<Semaphore> bArrived)
\brief Initialise vector and evently add thread jobs
\param vector of threads, aArrived(Semaphore) & bArrived(Semaphore)
 */

void startVector(std::vector<std::thread> &threads, std::shared_ptr<Semaphore> aArrived, std::shared_ptr<Semaphore> bArrived){
    for (int i = 0; i < size; i++){
        std::this_thread::sleep_for(std::chrono::milliseconds(200));
        if (i < 4){
            std::thread current_thread = std::thread(taskOne, aArrived, bArrived, i);
            threads.push_back(move(current_thread));
        }else{
            std::thread current_thread = std::thread(taskTwo, aArrived, bArrived, i);
            threads.push_back(move(current_thread));
        }
    }
}

/*!
\fn int main()
\brief Main function
*/

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
