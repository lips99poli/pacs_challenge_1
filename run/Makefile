SOURCES = GD_Abstract.cpp GD_ApproximateLineSearch.cpp GD_InverseDecay.cpp GD_ExponentialDecay.cpp
OBJECTS = GD_Abstract.o GD_ApproximateLineSearch.o GD_InverseDecay.o GD_ExponentialDecay.o main.o
EXEC = main

CXXFLAGS = -std=c++20 -c
CPPFLAGS = -I ../include -I ../include/Library_GD
DIR_SOLVER = ../include/Library_GD/


.PHONY = all clean distclean

main: $(OBJECTS)
	@$(CXX) $(OBJECTS) -o main

GD_Abstract.o:
	@$(CXX) $(CXXFLAGS) $(DIR_SOLVER)GD_Abstract.cpp $(CPPFLAGS)

GD_ApproximateLineSearch.o:
	@$(CXX) $(CXXFLAGS) $(DIR_SOLVER)GD_ApproximateLineSearch.cpp $(CPPFLAGS)

GD_InverseDecay.o:
	@$(CXX) $(CXXFLAGS) $(DIR_SOLVER)GD_InverseDecay.cpp $(CPPFLAGS)

GD_ExponentialDecay.o:
	@$(CXX) $(CXXFLAGS) $(DIR_SOLVER)GD_ExponentialDecay.cpp $(CPPFLAGS)

main.o:
	@$(CXX) $(CXXFLAGS) main.cpp $(CPPFLAGS)

clean:
	@$(RM) *.o 

distclean: clean
	@$(RM) main