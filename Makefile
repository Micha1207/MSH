# Makefile for MSH.
# This is part of the Micha1207's Shell program (MSH)
#
# Author:  Micha1207
# Date:    Nov 8, 2025
# License: GNU GPL v3 (full license in LICENSE file)
# This program comes with NO WARRANTY; to the extent permitted by law.
CC     = gcc
SRC    = main.c
OBJ    = main.o
TARGET = msh

$(TARGET): $(OBJ)
	$(CC) $(OBJ) -o $(TARGET)

$(OBJ): $(SRC)
	$(CC) $(SRC) -c -o $(OBJ)

clean:
	rm -rf $(OBJ) $(TARGET)
