CC = gcc-13
CFLAGS = -Wall -Wextra -std=c17
LDFLAGS = -lm -lmysqlclient

#variable
TARGET = a.out
SOURCES = connectC.c

all: $(TARGET)

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $^ -o $@ $(LDFLAGS)

clean:
	rm -f $(TARGET)
