CXX = g++
CXXFLAGS = -Wall -g -I include -pthread

thread-pool: main.cpp src/ThreadPool.o
	$(CXX) $(CXXFLAGS) main.cpp src/ThreadPool.o -o thread-pool

src/ThreadPool.o: include/ThreadPool.h src/ThreadPool.cpp
	$(CXX) $(CXXFLAGS) -c src/ThreadPool.cpp -o src/Threadpool.o

run:
	./thread-pool

val:
	valgrind ./thread-pool