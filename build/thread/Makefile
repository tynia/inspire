all: threads

# which compiler
CC = g++

# include directory
INCLUDE = ../threads

# compile flags
CFLAGS = -O -ggdb -Wall -D_LINUX -D_DEBUG -I$(INCLUDE)

# link flags
LFLAGS = -lpthread -lm -ldl

# target
threads: threads.o thdMgr.o thdMainTask.o thdTaskMgr.o base.o writer.o thread.o \
utilFile.o
	$(CC) -o threads threads.o thdMgr.o thdMainTask.o thdTaskMgr.o base.o \
	writer.o thread.o utilFile.o $(LFLAGS)

threads.o: ../sample/threads.cpp
	$(CC) -I$(INCLUDE) $(CFLAGS) -c ../sample/threads.cpp

thread.o: ../threads/thread.cpp
	$(CC) -I$(INCLUDE) $(CFLAGS) -c ../threads/thread.cpp

thdMgr.o: ../threads/thdMgr.cpp
	$(CC) -I$(INCLUDE) $(CFLAGS) -c ../threads/thdMgr.cpp

thdMainTask.o: ../threads/task/thdMainTask.cpp
	$(CC) -I$(INCLUDE) $(CFLAGS) -c ../threads/task/thdMainTask.cpp

thdTaskMgr.o: ../threads/task/thdTaskMgr.cpp
	$(CC) -I$(INCLUDE) $(CFLAGS) -c ../threads/task/thdTaskMgr.cpp

base.o: ../threads/logger/base.cpp
	$(CC) -I$(INCLUDE) $(CFLAGS) -c ../threads/logger/base.cpp

writer.o: ../threads/logger/writer.cpp
	$(CC) -I$(INCLUDE) $(CFLAGS) -c ../threads/logger/writer.cpp

utilFile.o: ../threads/util/utilFile.cpp
	$(CC) -I$(INCLUDE) $(CFLAGS) -c ../threads/util/utilFile.cpp

clean:
	rm -f *.o