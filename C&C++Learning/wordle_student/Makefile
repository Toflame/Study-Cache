CC = g++
 
CXXFLAGS  = -g -Wall -std=c++11 -I"./args" -O2

TARGET = main
 
all: $(TARGET)
 
$(TARGET): src/$(TARGET).cpp src/game.h src/state.h src/words.h
	$(CC) $(CXXFLAGS) -o $(TARGET) src/$(TARGET).cpp

clean:
	rm main