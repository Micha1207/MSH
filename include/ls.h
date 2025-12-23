/*
 * ls.h
 * Header file for src/ls.c.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Dec 23, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#ifndef LS_H
#define LS_H

// Include necessary libs
#include <stdio.h>
#include <dirent.h>

// Function prototype (full function in src/ls.c)
int cmd_ls(const char *user_path);

#endif
