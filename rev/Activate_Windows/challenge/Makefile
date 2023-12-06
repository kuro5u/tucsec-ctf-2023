CC = gcc
CCFLAGS = -Wall -Wextra -pedantic

SRC = main.c
TARGET = activate_windows

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CCFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
