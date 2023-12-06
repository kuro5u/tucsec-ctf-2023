CC = gcc
CCFLAGS = -Wall -Wextra -pedantic
PRFLAGS = -fno-stack-protector

SRC = main.c
TARGET = baby_bof

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CCFLAGS) $(PRFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
