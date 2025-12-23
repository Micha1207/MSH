/*
 * cmd-parser.h
 * Header file for src/cmd-parser.c
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Dec 23, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#ifndef CMD_PARSER_H
#define CMD_PARSER_H

/* Include necessary libraries and files */
#include <stdio.h>
#include <string.h>

#include "cat.h"
#include "cd.h"
#include "cls.h"
#include "echo.h"
#include "grep.h"
#include "help.h"
#include "ls.h"
#include "pwd.h"
#include "rm.h"
#include "run.h"

#include "colors.h"

// Function prototype (full function in src/cmd-parser.c)
int runcmd(const char *cmd);

#endif
