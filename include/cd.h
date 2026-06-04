/*
 * cd.h
 * MSH - Micha1207's Shell program.
 *
 * This is a header file for src/cd.c
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Mar 11, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#ifndef CD_H
#define CD_H 

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

int cmd_cd(const char *path);

#endif
