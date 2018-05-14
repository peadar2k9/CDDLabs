# Peter Cronin - C00210495

CC=g++
CFLAGS = -std=c++11 -pthread
CFILES = mutex.cpp Semaphore.cpp
HFILES = Semaphore.h
EXE = mutex

ALL: $(CFILES) $(HFILES)
	$(CC) -o $(EXE) $(CFILES) $(CFLAGS)

DEBUG: DEBUGFLAGS = -g -O0
DEBUG: ALL

clean:
	rm *.o
