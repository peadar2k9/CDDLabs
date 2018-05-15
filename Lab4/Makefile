#Author: Peter Cronin
#Date: 06/11/2017
#Makefile contains commands to compile project using "make"

CC = g++
CFLAGS = -std=c++11 -pthread
CFILES = Barrier.cpp Semaphore.cpp main.cpp
HFILES = Semaphore.h Barrier.h
EXE = barrier

ALL: $(CFILES) $(HFILES)
	$(CC) -o $(EXE) $(CFILES) $(CFLAGS)

#adds gdb debugging functionality
DEBUG: DEBUGFLAGS = -g -O0 -Wall
DEBUG: ALL

#deletes all.o files (tidying up)
clean:
	rm *.o
