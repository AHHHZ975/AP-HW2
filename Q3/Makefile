CXX = g++
CXXFLAGS = -std=c++17 -Wall -c
LXXFLAGS = -std=c++17
OBJECTS = main.o SimplifyDatabase.o
TARGET = main


$(TARGET): $(OBJECTS)
	$(CXX) $(LXXFLAGS) $(OBJECTS) -o $(TARGET)
main.o: main.cpp
	$(CXX) $(CXXFLAGS) main.cpp
SimplifyDatabase.o: SimplifyDatabase.cpp SimplifyDatabase.h
	$(CXX) $(CXXFLAGS) SimplifyDatabase.cpp
clean:
	rm -f $(TARGET) $(OBJECTS)
