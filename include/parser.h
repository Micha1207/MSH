/*
 * parser.h
 * MSH - Micha1207's Shell program.
 *
 * This is a header file for src/parser.c
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Mar 10, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#ifndef PARSER_H
#define PARSER_H 

#include <stdio.h>
#include <string.h>

#include "cat.h"
#include "cd.h"
#include "clear.h"
#include "echo.h"
#include "help.h"
#include "ls.h"
#include "pwd.h"
#include "rm.h"
#include "run.h"

#include "colors.h"

int runcmd(const char *cmd);

#endif
