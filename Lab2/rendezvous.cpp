#include "Semaphore.h"
#include <iostream>
#include <thread>

void taskOne(std::shared_ptr<Semaphore> aArrived, std::shared_ptr<Semaphore> bArrived){
  std::cout <<"Started Task 1 \n";
  aArrived->Signal();
  std::cout << "Task 2 Waiting \n";
  bArrived -> Wait();
  std::cout << "Task 1 Done \n";
}
void taskTwo(std::shared_ptr<Semaphore> aArrived, std::shared_ptr<Semaphore> bArrived){
  std::cout <<"Started Task 2 \n";  
  bArrived->Signal();
  std::cout << "Task 1 Waiting \n";
  aArrived -> Wait();
  std::cout << "Task 2 Done \n";
}

int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> aArrived( new Semaphore);
  std::shared_ptr<Semaphore> bArrived( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo, aArrived, bArrived);
  threadTwo=std::thread(taskOne, aArrived, bArrived);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}
