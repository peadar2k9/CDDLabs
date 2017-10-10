CC=g++
CFLAGS= -std=c++11 -pthread
DEBUGFLAGS= -g -std=c++11 -pthread
FILES= mutex.cpp Semaphore.cpp
OUT_EXE=mutex

build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES) $(CFLAGS)

clean:
	rm *.o