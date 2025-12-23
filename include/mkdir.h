/*
 * mkdir.h
 * Header file for src/mkdir.c
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Dec 23, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#ifndef MKDIR_H
#define MKDIR_H

//Include necessary libs
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

// Function prototype (full function in src/mkdir.c)
int cmd_mkdir(const char *name);

#endif
