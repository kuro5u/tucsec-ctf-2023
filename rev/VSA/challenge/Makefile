CC = gcc
CCFLAGS = -Wall -Wextra -pedantic

SRC = main.c
TARGET = vsa

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CCFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
