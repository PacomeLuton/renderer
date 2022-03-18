CXX=clang++ -std=c++17
FLAGS=-O3 -Xpreprocessor -fopenmp 
LINKFLAGS=-lomp 
SRC=src/main.cpp
EXEC=main

all:
	time $(CXX) $(FLAGS) $(SRC) $(LINKFLAGS) -o $(EXEC)

run: all
	time ./main

clean:
	rm $(EXEC) -n 8

# SPECIAL BUILT-IN RULES
.PHONY: all clean