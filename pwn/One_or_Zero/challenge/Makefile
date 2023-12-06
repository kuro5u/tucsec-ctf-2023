CC = gcc
CCFLAGS = -Wall -Wextra -pedantic
PRFLAGS = -no-pie -fno-stack-protector

SRC = main.c
TARGET = oneorzero

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CCFLAGS) $(PRFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
