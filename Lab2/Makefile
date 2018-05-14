# Peter Cronin - C00210495

CC=g++
CFLAGS= -std=c++11 -pthread
CFILES= rendezvous.cpp Semaphore.cpp
HFILES=Semaphore.h
EXE=rendezvous

ALL: $(CFILES) $(HFILES)
	$(CC) -o $(EXE) $(CFILES) $(CFLAGS)
CLEAN:
	rm *.o