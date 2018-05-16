/*! 
\author Peter Cronin
\date 15/11/2017
\email peadarcronin1@gmail.com
\file SafeBuffer.cpp
\brief file that contains functions for adding and removing to a buffer
\license GNU (General Public License)
*/

#include "SafeBuffer.h"
#include <iostream>

SafeBuffer::SafeBuffer() {
    mutex = std::make_shared<Semaphore>(1);
    items = std::make_shared<Semaphore>(0);    
    space = std::make_shared<Semaphore>(50);
}

/*!
\fn void SafeBuffer::Add(char character)
\brief Function that checks for space and then adds the character using a mutex
\param char character
*/

void SafeBuffer::Add(char character) {
    space->Wait();
    mutex->Wait();
    buffer.push(character);
    mutex->Signal();
    items->Signal();
}

/*!
\fn void SafeBuffer::Remove()
\brief Function that checks for consumer item then removes. Then releases mutex and creates a space
*/

char SafeBuffer::Remove() {
    char character;
    items->Wait();
    mutex->Wait();
    character = buffer.front();
    buffer.pop();
    mutex->Signal();
    space->Signal();
    return character;
}