/*
 * parser.h
 * MSH - Micha1207's Shell program.
 *
 * Header file for src/parser.c
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    June 3, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#ifndef PARSER_H
#define PARSER_H

#include <string.h>
#include <stdio.h>

#include "cat.h"
#include "cd.h"
#include "clear.h"
#include "echo.h"
#include "help.h"
#include "ls.h"
#include "mkdir.h" 
#include "parser.h"
#include "pwd.h"
#include "rm.h"
#include "run.h"
#include "touch.h"
#include "colors.h"

#define MAX_ARG_NUM 16

int parser(char *string, size_t size);

#endif
