CC=clang
CXX=clang++
CXXFLAGS=-std=c++20 -Wall -Wpedantic -Wextra


build:
	clang++ $(CXXFLAGS) main.cpp 

run:
	clang++ $(CXXFLAGS) -o main main.cpp && ./main && rm -f main

test-table:
	clang++ $(CXXFLAGS) -o hashtabletest test/hashtable.test.cpp && ./hashtabletest && rm -f hashtabletest

test-list:
	clang++ $(CXXFLAGS) -o linkedlisttest test/linkedlist.test.cpp && ./linkedlisttest && rm -f linkedlisttest

test-node:
	clang++ $(CXXFLAGS) -o nodetest test/node.test.cpp && ./nodetest && rm -f nodetest

clean:
	rm -f a.exe main main.pdb main.ilk linkedlisttest nodetest

debug:
	clang++ $(CXXFLAGS) -g -o main main.cpp 