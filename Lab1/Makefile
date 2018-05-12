# Peter Cronin - C00210495

CC=g++
CFLAGS= -std=c++11 -pthread
CFILES= signal.cpp Semaphore.cpp
HFILES=Semaphore.h
EXE=signal

ALL: $(CFILES) $(HFILES)
	$(CC) -o $(EXE) $(CFILES) $(CFLAGS)
CLEAN:
	rm *.o
