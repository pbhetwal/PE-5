# Parikshit Bhetwal 
# Dennis Lim 
# PE 5
# This is the make file for 
# programming exercise five.

# Compiler 
CXX = g++
# Flags, using C++17
CXXFLAGS	= -std=c++17 -Wall
CXXTESTFLAGS = --coverage # can be used to generate files that help calculate unit test coverage
CXXGDB = -ggdb
# make all 
all: test
# make clean
clean:
	rm test Rectangle.o
# make test
test: Rectangle.o test.cpp
	$(CXX) $(CXXFLAGS) test.cpp Rectangle.o -o test
# make cov
cov: Rectangle.o test.cpp
	$(CXX) $(CXXFLAGS) $(CXXTESTFLAGS) test.cpp Rectangle.o -o test

Rectangle.o: Rectangle.cpp
	$(CXX) $(CXXFLAGS) -c Rectangle.cpp
