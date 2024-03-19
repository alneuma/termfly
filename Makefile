SHELL=/bin/bash

CC = gcc

CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpedantic
# CFLAGS += -Wmissing-declarations
CFLAGS += -DUNITY_SUPPORT_64 -DUNITY_OUTPUT_COLOR

INC_DIR = inc
SRC_DIR = src
TEST_FRAMEWORK_SRC_DIR = test_framework_unity
TEST_FRAMEWORK_INC_DIR = test_framework_unity
TEST_DIR = test

SRC_FILES = $(wildcard $(SRC_DIR)/*.c)
INC_FILES = $(wildcard $(INC_DIR)/*.h)
TEST_FRAMEWORK_SRC_FILES = $(wildcard $(TEST_FRAMEWORK_SRC_DIR)/*.c)
TEST_FRAMEWORK_INC_FILES = $(wildcard $(TEST_FRAMEWORK_INC_DIR)/*.h)


main: $(SRC_FILES) $(INC_FILES)
	$(CC) $(CFLAGS) $(SRC_FILES) -o main -I$(INC_DIR)

test.out: $(objects_test)
	cc $(CFLAGS) $(objects_test) -o test.out $(LIBS)

.PHONY: test
test: test.out
	./test.out

.PHONY: clean
clean:
	rm -rf *.o *.out *.x
