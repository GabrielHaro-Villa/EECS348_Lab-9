CXX = g++
CXXFLAGS = -std=c++11 -Wall

TARGET = main
SRCS = main.cpp matrix.cpp

all: $(TARGET)

$(TARGET):
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

clean:
	rm -f $(TARGET)