CC=g++
CFLAGS=-c -Wall
TARGET=MyParser

SRC=$(shell find $("ParserCode") -name '*.cpp')
OBJ=$(patsubst %.cpp, %.o, $(SRC))

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o : %.cpp
	$(CC) -c $< -o $@

clean:
	rm -rf $(shell find $("ParserCode") -name '*.o') *.o

