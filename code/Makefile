CC = gcc
CFLAGS = -Wall -Wextra -std=c17
LDFLAGS = -lm -lpng -lmysqlclient


#variable
TARGET = a.out
SOURCES = ImageProcessor.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGET)
