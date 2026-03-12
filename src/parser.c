/*
 * parser.c
 * MSH - Micha1207's Shell program.
 *
 * Parse string commands to arguments and run them.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Mar 9, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>
#include <string.h>

/* Include commands' header files. */
#include "cat.h"
#include "cd.h"
#include "clear.h"
#include "echo.h"
#include "help.h"
#include "ls.h"
#include "mkdir.h"
#include "pwd.h"
#include "rm.h"
#include "run.h"
#include "touch.h"

#include "parser.h"
#include "colors.h" /* Color definitions */

/*
 * Parse command string to arguments: arg[0] is always
 * the command name, all other elements are its arguments.
 * Check if the command is MSH builtin and run it, else
 * run from $PATH environment variable.
 * Returns 0 on success, error if command cannot be found.
 * If no command entered, returns 0.
 */
int runcmd(const char *cmd){
  char cmd_copy[512], *arg[16];
  int i = 0;
  strncpy(cmd_copy, cmd, sizeof(cmd_copy));
  cmd_copy[sizeof(cmd_copy) - 1] = '\0';
  char *token = strtok(cmd_copy, " ");

  while (token != NULL && i < 15){
    arg[i] = token;
    i = i + 1;
    token = strtok(NULL, " ");
  }

  arg[i] = NULL;

  if (!arg[0]){ return 0; } else {
      if (strcmp (arg[0], "cat") == 0 && arg[1]){
	cmd_cat(arg[1]);
      } else if (strcmp (arg[0], "cd") == 0 && arg[1]){
	cmd_cd(arg[1]);
      } else if (strcmp (arg[0], "cls") == 0 || strcmp (arg[0], "clear") == 0){
	cmd_clear();
      } else if (strcmp (arg[0], "echo") == 0 && arg[1]){
	cmd_echo(arg);
      } else if (strcmp (arg[0], "ls") == 0 || strcmp (arg[0], "dir") == 0){
	cmd_ls(arg[1]);
      } else if (strcmp (arg[0], "mkdir") == 0 && arg[1]){
	cmd_mkdir(arg[1]);
      } else if (strcmp (arg[0], "touch") == 0 && arg[1]){
	cmd_touch(arg[1]);
      } else if (strcmp (arg[0], "pwd") == 0){
	cmd_pwd();
      } else if (strcmp (arg[0], "rm") == 0 && arg[1]){
	cmd_rm(arg[1]);
      } else if (strcmp (arg[0], "help") == 0){
	cmd_help();
      } else if (strcmp (arg[0], "run") == 0){
	cmd_run(&arg[1]);
      } else {
	cmd_run(arg);
      }
    }

  return 0;
}
