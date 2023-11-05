CC=g++ -std=c++20
CFLAGS=-g -std=c++20 -Wall -pedantic
TARGET=ParserPPTX

SRC=$(shell find . $("3.PptxFromParser") -name '*.cpp')
OBJ=$(patsubst %.cpp, %.o, $(SRC))

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

%.o : %.cpp
	$(CC) -c $< -o $@

clean:
	find . -name '*.o' -type f -delete