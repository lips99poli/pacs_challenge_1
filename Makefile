SOURCES = GD_Abstract.cpp GD_ApproximateLineSearch.cpp GD_InverseDecay.cpp GD_ExponentialDecay.cpp
OBJECTS = GD_Abstract.o GD_ApproximateLineSearch.o GD_InverseDecay.o GD_ExponentialDecay.o main.o
EXEC = main

CXXFLAGS = -std=c++20 -c
CPPFLAGS =  -I ../pacs-examples/Examples/src/Utilities -I ./Library_GD -I .


.PHONY = all clean distclean

main: $(OBJECTS)
	@$(CXX) $(OBJECTS) -o main

GD_Abstract.o:
	@$(CXX) $(CXXFLAGS) ./Library_GD/GD_Abstract.cpp $(CPPFLAGS)

GD_ApproximateLineSearch.o:
	@$(CXX) $(CXXFLAGS) ./Library_GD/GD_ApproximateLineSearch.cpp $(CPPFLAGS)

GD_InverseDecay.o:
	@$(CXX) $(CXXFLAGS) ./Library_GD/GD_InverseDecay.cpp $(CPPFLAGS)

GD_ExponentialDecay.o:
	@$(CXX) $(CXXFLAGS) ./Library_GD/GD_ExponentialDecay.cpp $(CPPFLAGS)

main.o:
	@$(CXX) $(CXXFLAGS) main.cpp $(CPPFLAGS)

clean:
	@$(RM) *.o 

distclean: clean
	@$(RM) main