/*! 
\author Peter Cronin
\date 13/10/2017
\email peadarcronin1@gmail.com
\file mutex.cpp
\brief Mutex demo
\license GNU (General Public License)
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>
#include <mutex>

int common = 0; 

/*!
\fn void taskOne(std::shared_ptr<Semaphore> mutex)
\brief Function that enters once task 2 completes
\param barriers aArrived and bArrived passed in
*/

void taskOne(std::shared_ptr<Semaphore> mutex)
{  
  mutex->Wait();
  std::cout << "(Task 1) Count is now " << common << std::endl;  
  common++;  
  std::cout << "(Task 1) After increment it is " << common << std::endl;
  mutex->Signal(); 
}

/*!
\fn void taskTwo(std::shared_ptr<Semaphore> mutex)
\brief Function that completes first, prevents access to task 1 until done
\param mutex (Semaphore)
*/

void taskTwo(std::shared_ptr<Semaphore> mutex)
{  
  mutex->Wait();
  std::cout << "(Task 2) Count is now " << common << std::endl;  
  common++;  
  std::cout << "(Task 2) After increment it is " << common << std::endl;
  mutex->Signal();
}

/*!
\fn int main()
\brief Main function
*/

int main(void)
{
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> mutex(new Semaphore(1));
  std::cout << "Increment 0 to 2" << "\n";  
  threadOne=std::thread(taskTwo, mutex);
  threadTwo=std::thread(taskOne, mutex);
  std::cout << "Launched from the main \n";
  threadOne.join();
  threadTwo.join();
  return 0;
}