CC=g++ -std=c++17
CFLAGS=-g -std=c++17 -Wall -pedantic
TARGET=ParserPPTX

SRC=$(shell find . $("2.ParserToPptx") -name '*.cpp')
OBJ=$(patsubst %.cpp, %.o, $(SRC))

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o : %.cpp
	$(CC) -c $< -o $@

clean:
	rm -rf $(shell find $("2.ParserToPptx") -name '*.o') *.o