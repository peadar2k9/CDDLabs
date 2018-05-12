/*! 
\author Peter Cronin
\date 12/10/2017
\email peadarcronin1@gmail.com
\file signal.cpp
\brief Signalling with Semaphores - Creates two threads where one thread signals the other using a common Semaphore
\license GNU (General Public License)
*/

#include "Semaphore.h"
#include <iostream>
#include <thread>

/*!
\fn void taskOne(std::shared_ptr<Semaphore> theSemaphore)
\brief Function to be called by thread one
\param Instance of Semaphore
*/
void taskOne(std::shared_ptr<Semaphore> theSemaphore){
  std::cout <<"I ";
  std::cout << "must ";
  std::cout << "print ";
  std::cout << "first"<<std::endl;
  theSemaphore->Signal();
}

/*!
\fn void taskTwo(std::shared_ptr<Semaphore> theSemaphore)
\brief Function to be called by thread one
\param Instance of Semaphore
*/
void taskTwo(std::shared_ptr<Semaphore> theSemaphore){
  theSemaphore->Wait();
  std::cout <<"This ";
  std::cout << "will ";
  std::cout << "appear ";
  std::cout << "second"<<std::endl;
}

/*!
\fn int main()
\brief Main function to create two threads and assigns to them functions and a semaphore
*/
int main(void){
  std::thread threadOne, threadTwo;
  std::shared_ptr<Semaphore> sem( new Semaphore);
  /**< Launch the threads  */
  threadOne=std::thread(taskTwo,sem);
  threadTwo=std::thread(taskOne,sem);
  std::cout << "Launched from the main\n";
  threadOne.join();
  threadTwo.join();
  return 0;
}