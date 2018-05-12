# Peter Cronin - C00210495

CC=g++
CFLAGS= -std=c++11 -pthread
FILES= mutex.cpp Semaphore.cpp
OUT_EXE=mutex

build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES) $(CFLAGS)

DEBUG: DEBUGFLAGS = -g -O0
	DEBUG: build

clean:
	rm *.o
