# Peter Cronin - C00210495

CC=g++
CFLAGS= -std=c++11 -pthread
FILES= rendezvous.cpp Semaphore.cpp
OUT_EXE=rendezvous

build: $(FILES)
	$(CC) -o $(OUT_EXE) $(FILES) $(CFLAGS)

clean:
	rm *.o