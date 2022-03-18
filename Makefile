CXX=clang++ -std=c++17
FLAGS=-O3 -Xpreprocessor -fopenmp 
LINKFLAGS=-lomp 

EXEC=main

CFILES= $(shell find src -name "*.cpp")
OFILES= $(patsubst src/%.cpp,obj/%.o,$(CFILES))
INCLUDE= $(patsubst src/%.cpp,dep/%.d,$(CFILES))

all : bin/$(EXEC)

run : all
	./bin/main -n 8 -t 1000

bin/$(EXEC) : $(OFILES)
	$(CXX) -v -o $@ $^ $(LINKFLAGS)

obj/%.o: src/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(FLAGS) -o $@ -c $<

dep/%.d: src/%.cpp
	mkdir -p $(dir $@)
	$(CXX) $(FLAGS) -c $< -M -MF dep/$*.d -MT $@

clean:
	$(RM) $(OFILES) $(INCLUDE)

mrproper: clean
	$(RM) bin/$(EXEC)

dir:
	@mkdir -p obj; mkdir -p bin; mkdir -p dep

-include $(INCLUDE)