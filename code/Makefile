CC = gcc
CFLAGS = -Wall -Wextra -std=c17
LDFLAGS = -lm


#variable
TARGET = a.out
SOURCES = FPP.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGET)
