CC = g++
CFLAGS = -std=c++11 -Wall

VALGRIND= valgrind --leak-check=full --track-origins=yes --log-file=valgrind_output.txt --show-leak-kinds=all -s

# List of source files
SRCS = main.cpp Card.cpp Deck.cpp Player.cpp Game.cpp

# Object files
OBJS = $(SRCS:.cpp=.o)

# Name of the executable
TARGET = main

valgrind: $(TARGET)
	$(VALGRIND) ./$<

all: $(TARGET)
	./main

$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(TARGET)