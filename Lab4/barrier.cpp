#include "Semaphore.h"
#include <iostream>
#include <thread>

int count = 0;
int times = 0;

void barrier(std::shared_ptr<Semaphore> mutex, std::shared_ptr<Semaphore> turnstile1, std::shared_ptr<Semaphore> turnstile2 ){
    mutex->Wait();
    count += 1;
    if (count == n) {
        turnstile2->Wait();     /*locks the second turnstile*/
        turnstile->Signal();    /*Unlocks the first turnstile*/
    }
    mutex->Signal();  
    turnstile->Wait();
    std::cout << "\nTurnstile 1 Passed";
    turnstile->Signal();
    /*critical point*/
    mutex->Wait();
    count -= 1;
    if (count == 0) {
        turnstile1->Wait();     /*locks the first turnstile*/
        turnstile2->Signal();   /*unlocks the second turnstile*/
        times ++;
    }
    mutex->Signal();
    turnstile2->Wait();
    std::cout << "\nTurnstile 2 Passed";
    turnstile2->Signal();
    }
}

int main(void){
  std::thread threadOne, threadTwo, threadThree;
  std::shared_ptr<Semaphore> mutex( new Semaphore(1));
  std::shared_ptr<Semaphore> turnstile1( new Semaphore(0));
  std::shared_ptr<Semaphore> turnstile2( new Semaphore(1));
  
  /**< Launches the threads  */
  threadOne=std::thread(reusableBarrier, mutex, turnstile1, turnstile2);
  threadTwo=std::thread(reusableBarrier, mutex, turnstile1, turnstile2);
  threadThree=std::thread(reusableBarrier, mutex, turnstile1, turnstile2);
  
  std::cout << "Launched from the main\n";
  
  threadOne.join();
  threadTwo.join();
  threadThree.join();
  
  return 0;
}