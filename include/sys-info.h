/*
 * sys-info.h
 * MSH - Micha1207's Shell program.
 *
 * This is a header file for src/sys-info.c
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    June 3, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#ifndef SYS_INFO_H
#define SYS_INFO_H

#include <unistd.h>
#include <stdlib.h>
#include <string.h>

int sys_info(char username[64], char hostname[128]);

#endif
