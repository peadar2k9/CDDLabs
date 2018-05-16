#Author: Peter Cronin
#Date: 15/11/2017
#Makefile contains commands to compile project using "make"

CC = g++
CFLAGS = -std=c++11 -pthread
CFILES = SafeBuffer.cpp Semaphore.cpp main.cpp
HFILES = Semaphore.h SafeBuffer.h
EXE = prodCom

ALL: $(CFILES) $(HFILES)
	$(CC) -o $(EXE) $(CFILES) $(CFLAGS)

#adds gdb debugging functionality
DEBUG: DEBUGFLAGS = -g -O0 -Wall
DEBUG: ALL

#creates Doxygen documentation. Checks to see if any already exists and overwrites them
doc: ALL
	if [ -e "Doxyfile" ]; then rm "Doxyfile"; fi;
	if [ -d "html" ] ; then  rm -rf "html";  fi
	if [ -d "latex" ] ; then  rm -rf "latex";  fi
	echo "PROJECT_NAME = \"Lab 5\"" >> Doxyfile
	echo "PROJECT_BRIEF = \"Producer/Consumer\"" >> Doxyfile
	echo "PROJECT_NUMBER = 1.0" >> Doxyfile
	echo "EXTRACT_ALL = YES" >> Doxyfile
	doxygen Doxyfile

#deletes all.o files (tidying up)
clean:
	rm *.o