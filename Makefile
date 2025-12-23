# Makefile for MSH.
# This is part of the Micha1207's Shell program (MSH)
# More info in doc/Makefile.txt
#
# Author:  Micha1207
# Date:    Dec 13, 2025
# License: GNU GPL v3 (full license in LICENSE file)
# This program comes with NO WARRANTY; to the extent permitted by law.
CC      = gcc
CFLAGS  = -Wall -Wextra -std=c99 -Iinclude -g
TARGET  = msh
SRC_DIR = src
OBJ_DIR = obj

SRCS    = $(wildcard $(SRC_DIR)/*.c)
OBJS    = $(patsubst $(SRC_DIR)/%.c, $(OBJ_DIR)/%.o, $(SRCS))

.PHONY: all

all: $(OBJ_DIR) $(TARGET)

$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)/

$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ_DIR)/ $(TARGET)

install:
	cp $(TARGET) /bin/$(TARGET)

uninstall:
	rm -rf /bin/$(TARGET)
