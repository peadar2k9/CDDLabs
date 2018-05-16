/*! 
\author Peter Cronin
\date 15/11/2017
\email peadarcronin1@gmail.com
\file SafeBuffer.cpp
\brief file that contains functions for adding and removing to a buffer
\license GNU (General Public License)
*/
#include <mutex>
#include "Semaphore.h"
#include <queue>

class SafeBuffer {
 public:
  std::shared_ptr<Semaphore> mutex;
  std::shared_ptr<Semaphore> items;
  std::shared_ptr<Semaphore> space;
  std::queue<char> buffer;
  SafeBuffer();
  void Add(char c);
  char Remove();
};