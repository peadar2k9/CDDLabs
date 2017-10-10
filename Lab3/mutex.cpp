/* Peter Cronin - C00210495 */

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <mutex>

int count = 0; 

void taskOne(std::shared_ptr<Semaphore> mutex)
{  
  mutex->Wait();
  count += 1;
  std::cout << count;
  std::cout << "\n";
  mutex->Signal(); 
}

int main(void)
{
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> mutex(new Semaphore);
  threadOne=std::thread(taskOne, mutex);
  threadTwo=std::thread(taskOne, mutex);
  mutex->Signal();  
  std::cout << "Launched from the main \n";
  threadOne.join();
  threadTwo.join();
  return 0;
}