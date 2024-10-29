CC = gcc
CCFLAGS = -Wall -Wextra -pedantic
PRFLAGS = -gdwarf-4 -fcf-protection=none -no-pie -fno-stack-protector

SRC = main.c
TARGET = mr_ropot

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CCFLAGS) $(PRFLAGS) -o $@ $<

clean:
	rm -f $(TARGET)
