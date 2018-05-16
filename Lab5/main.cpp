/*! 
\author Peter Cronin
\date 15/11/2017
\email peadarcronin1@gmail.com
\file main.cpp
\brief Producer/Consumer main file
\license GNU (General Public License)
*/

#include "SafeBuffer.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <map>

std::map<char,int> characterNumber;


/*!
\fn void Consumer(std::shared_ptr<SafeBuffer> buffer)
\brief Consumer function that removes a character from the buffer
\param buffer
*/
void Consumer(std::shared_ptr<SafeBuffer> buffer) {
    char removed;
    while(removed != 'X'){
        removed = buffer->Remove();
        characterNumber[removed]++;
        std::cout << "Consumed : " << removed << std::endl;
        std::this_thread::sleep_for(std::chrono::milliseconds(std::rand()%1000));
    }  
}

/*!
\fn void Producer(std::shared_ptr<SafeBuffer> buffer, char character)
\brief Producer function that adds a character to the buffer
\param buffer
*/
void Producer(std::shared_ptr<SafeBuffer> buffer, char character) {
    std::cout << "Produced : " << character << std::endl;
    std::this_thread::sleep_for(std::chrono::milliseconds(std::rand()%1000));
    buffer->Add(character);
}

/*!
\fn generateRandom()
\brief Generates random lowercase letter
*/
char generateRandom(){
    int r = rand() % 26;
    char random = (char)(r+97);
    return random;
}

/*!
\fn main()
\brief Main
*/
int main() {
    for(char i = 97; i < 123; ++i) {
        characterNumber[i] = 0;
    }
    int numberChars = 20;
    char random;
    std::shared_ptr<SafeBuffer> buffer(new SafeBuffer());
    std::thread threadProducer;
    std::thread threadConsumer;
    for(int i = 0; i < numberChars; ++i){
        char random = generateRandom();         
        threadProducer = std::thread(Producer, buffer, random);
        threadConsumer = std::thread(Consumer, buffer);
        threadConsumer.join();
        threadProducer.join();
    }
    for(char i = 97; i < 123; ++i) {
        if(characterNumber[i] > 0){
          std::cout << i << " showed up : " << characterNumber[i]  << std::endl;
        }
    }
    return 0;
}