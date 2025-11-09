CXX = g++
CXXFLAGS = -Iinclude -Wall -std=c++17
SRC = src/main.cpp src/cpu.cpp src/memory.cpp src/process.cpp
OUT = monitor

all: $(OUT)

$(OUT): $(SRC)
	$(CXX) $(SRC) $(CXXFLAGS) -o $(OUT)

clean:
	rm -f $(OUT)
