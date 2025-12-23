/*
 * cd.h
 * Header file for src/cd.c.
 * 
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Dec 23, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#ifndef CD_H
#define CD_H

// Include necessary libs
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// Function prototype (full funciton in src/cd.c) 
int cmd_cd(const char *path);

#endif
