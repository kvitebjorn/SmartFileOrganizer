CC = gcc
CFLAGS = -Wall -Wextra -std=c99
SRC = src/main.c src/file_type_detector.c
SRC_TEST = src/file_type_detector.c tests/tests_file_type_detector.c

OBJ = $(SRC:.c=.o)

LIBS = -lmagic 
LIBS_TEST = -lcunit
TARGET = sfo  # Executable name
TARGET_TEST = sfo_tests

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LIBS)

cunit: 
	$(CC) $(CFLAGS) $(SRC_TEST) -o $(TARGET_TEST) $(LIBS) $(LIBS_TEST)

clean:
	rm -f $(OBJ) $(TARGET)
