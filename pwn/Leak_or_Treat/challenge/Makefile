CC = gcc
CCFLAGS = -Wall -Wextra -pedantic
PRFLAGS = -fstack-protector-all

SRC = main.c
TARGET = leak_or_treat

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CCFLAGS) $(PRFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
