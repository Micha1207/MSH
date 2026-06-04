/*
 * parser.c
 * MSH - Micha1207's Shell program.
 *
 * Parse command string and run the command.
 * Argument 'string' is a pointer to command string, and 'size'
 * is it's size.
 * Returns exit status set by command.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    June 4, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
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

int parser(char *string, size_t size){
  char string_copy[size], *arg[MAX_ARG_NUM], *token;
  int exit_status = 0, i = 0;

  strncpy(string_copy, string, size);
  
  token = strtok(string_copy, " \t");
  while (token != NULL && i < MAX_ARG_NUM - 1){
    arg[i] = token;
    i++;
    token = strtok(NULL, " \t");
  }
  arg[i] = NULL;

  if (!arg[0]) return 0;
  else if (strcmp(arg[0], "cat") == 0){
    exit_status = cmd_cat(arg[1]);
  } else if (strcmp(arg[0], "cd") == 0){
    exit_status = cmd_cd(arg[1]);
  } else if (strcmp(arg[0], "cls") == 0 ||
	     strcmp(arg[0], "clear") == 0){
    exit_status = cmd_clear();
  } else if (strcmp(arg[0], "echo") == 0){
    exit_status = cmd_echo(arg);
  } else if (strcmp(arg[0], "help") == 0){
    exit_status = cmd_help();
  } else if (strcmp(arg[0], "ls") == 0){
    exit_status = cmd_ls(arg[1]);
  } else if (strcmp(arg[0], "mkdir") == 0){
    exit_status = cmd_mkdir(arg[1]);
  } else if (strcmp(arg[0], "pwd") == 0){
    exit_status = cmd_pwd();
  } else if (strcmp(arg[0], "rm") == 0){
    exit_status = cmd_rm(arg[1]);
  } else if (strcmp(arg[0], "touch") == 0){
    exit_status = cmd_touch(arg[1]);
  } else {
    exit_status = cmd_run(arg);
  }
  
  
  return exit_status;
}
