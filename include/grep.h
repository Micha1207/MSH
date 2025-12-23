/*
 * grep.h
 * Header file for src/grep.c.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Dec 23, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#ifndef GREP_H
#define GREP_H

// Include necessary libs
#include <stdio.h>
#include <string.h>

// Function prototype (full function in  src/grep.c)
int cmd_grep(const char *pattern, const char *file);

#endif 
