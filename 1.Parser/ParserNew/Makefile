CC=g++
CFLAGS=-c -Wall
TARGET=MyParser

SRC=$(shell find $("ParserNew") -name '*.cpp')
OBJ=$(patsubst %.cpp, %.o, $(SRC))

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o : %.cpp
	$(CC) -c $< -o $@

clean:
	rm -rf $(shell find $("ParserNew") -name '*.o') *.o

