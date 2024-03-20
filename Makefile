SELL=/bin/bash
MAKEFLAGS := --no-print-directory

## compiler settings ##

CC := gcc
CFLAGS += -g
CFLAGS += -Wall
CFLAGS += -Wextra
CFLAGS += -Wpedantic
CFLAGS += -DUNITY_SUPPORT_64 -DUNITY_OUTPUT_COLOR
CFLAGS += -Wmissing-declarations
CPPFLAGS = -I $(INC_DIR)

TEST_CFLAGS += -g
TEST_CFLAGS += -Wall
TEST_CFLAGS += -Wextra
TEST_CFLAGS += -Wpedantic
TEST_CFLAGS += -DUNITY_SUPPORT_64 -DUNITY_OUTPUT_COLOR
TEST_CPPFLAGS = -I $(TEST_INC_DIR)

## main program ##

INC_DIR := inc
SRC_DIR := src
OBJ_DIR := obj

SRCS := \
	main.c \
	person.c \
	date.c
SRCS := $(SRCS:%.c=$(SRC_DIR)/%.c)
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

NAME := name_database.x

## test program ##

TEST_DIR := test
TEST_SRC_DIR := $(TEST_DIR)/src
TEST_INC_DIR := $(TEST_SRC_DIR)/unity
TEST_OBJ_DIR := $(TEST_DIR)/obj
TEST_SRCS := \
	     test.c \
	     unity/unity.c
TEST_SRCS := $(TEST_SRCS:%.c=$(TEST_SRC_DIR)/%.c)
TEST_OBJS := $(TEST_SRCS:$(TEST_SRC_DIR)/%.c=$(TEST_OBJ_DIR)/%.o)

TEST_NAME := $(TEST_DIR)/test.x

## general ##

RM := rm -f
MAKEFLAGS := --no-print-directory
DIR_DUP = mkdir -p $(@D)

## rules ##

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -o $(NAME)
	$(info CREATED $(NAME))

$(TEST_NAME): $(OBJS) $(TEST_OBJS)
	$(CC) $(OBJS) $(TEST_OBJS) -o $(TEST_NAME)
	$(info CREATED $(TEST_NAME))

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(CFLAGS) $(CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

$(TEST_OBJ_DIR)/%.o: $(TEST_SRC_DIR)/%.c
	$(DIR_DUP)
	$(CC) $(TEST_CFLAGS) $(CPPFLAGS) $(TEST_CPPFLAGS) -c -o $@ $<
	$(info CREATED $@)

test: $(TEST_NAME)
	$(TEST_NAME)

mostlyclean:
	$(RM) $(OBJS) $(TEST_OBJS)

clean:
	$(RM) $(OBJS) $(NAME) $(TEST_OBJS) $(TEST_NAME)

.PHONY: test mostlyclean clean
.SILENT:
