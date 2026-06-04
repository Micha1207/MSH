/*
 * mkdir.h
 * MSH - Micha1207's Shell program.
 *
 * This is a header file for src/mkdir.c
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Mar 11, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#ifndef MKDIR_H
#define MKDIR_H 

#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

int cmd_mkdir(const char *name);

#endif
