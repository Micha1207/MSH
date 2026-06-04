/*
 * ls.h
 * MSH - Micha1207's Shell program.
 *
 * This is a header file for src/ls.c
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Mar 10, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#ifndef LS_H
#define LS_H 

#include <stdio.h>
#include <dirent.h>

int cmd_ls(const char *user_path);

#endif
