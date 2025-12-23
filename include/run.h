/*
 * run.h
 * Header file for src/run.c.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Dec 23, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#ifndef RUN_H
#define RUN_H

// Include necessary libs
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Functio prototype (full function in src/run.c)
int cmd_run(char *args[]);

#endif
