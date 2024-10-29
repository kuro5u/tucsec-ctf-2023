CC = gcc
CCFLAGS = -Wall -Wextra -pedantic
LIBFLAGS = -lssl -lcrypto

SRC = main.c
TARGET = vvsa

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CCFLAGS) -o $@ $< -L$(LIBFLAGS)

clean:
	rm -f $(TARGET)
