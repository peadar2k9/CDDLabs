# Peter Cronin - C00210495

CC = g++
CFLAGS = -std=c++11 -pthread
CFILES = Barrier.cpp Semaphore.cpp main.cpp
HFILES = Semaphore.h Barrier.h
EXE = barrier

ALL: $(CFILES) $(HFILES)
	$(CC) -o $(EXE) $(CFILES) $(CFLAGS)

DEBUG: DEBUGFLAGS = -g -O0 -Wall
DEBUG: ALL

clean:
	rm *.o
