CXX=clang++ -std=c++17
FLAGS=-O3 -Xpreprocessor -fopenmp 
POSTFLAGS=-lomp
SRC=src/main.cpp
EXEC=main

all:
	$(CXX) $(FLAGS) $(SRC) $(POSTFLAGS) -o $(EXEC)

run: all
	time ./main

clean:
	rm $(EXEC)

# SPECIAL BUILT-IN RULES
.PHONY: all clean