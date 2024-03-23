CPPFLAGS = -std=c++20 -c

#SOURCES = main.cpp Minimizer.cpp
#OBJECTS = main.o Minimizer.o
#EXEC = main

.PHONY: all clean distclean

all: main 

Minimizer.o: Minimizer.cpp
	$(CXX) $(CPPFLAGS) Minimizer.cpp

main.o: main.cpp
	$(CXX) $(CPPFLAGS) main.cpp

main: main.o Minimizer.o
	$(CXX) main.o Minimizer.o -o main 

#$(EXEC): $(OBJECTS)
	#$(CXX) $(CXXFLAGS) $(OBJECTS) -o $(EXEC)
#
#$(OBJECTS): $(SOURCES)
	#$(CXX) $(SOURCES)	
#
clean:
	$(RM) *.o

distclean: clean
	$(RM) main



