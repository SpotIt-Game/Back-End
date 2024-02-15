CC = gcc-13
CFLAGS = -Wall -Wextra -std=c17
LDFLAGS = -lm


#variable
TARGET = o
SOURCES = #x.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGET)
