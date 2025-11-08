/*
 * cmd-parser.h
 * Parse commands and run them.
 * This is part of the Micha1207's Shell program (MSH)
 *
 * Author:  Micha1207
 * Date:    Nov 8, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>
#include <string.h>
#include "cmd-def.h"
#include "colors.h"

int runcmd(const char *cmd) {
  char cmd_copy[256]; /* Buffer for cmd copy. */
  strncpy(cmd_copy, cmd, sizeof(cmd_copy)); /* Copy cmd into cmd_copy */
  cmd_copy[sizeof(cmd_copy) - 1] = '\0'; /* Make sure string always ends with '\0' (NULL) characher */
  
  char *arg[16]; /* Buffer for args */
  int i = 0;     /* Position in arg[]; */
  char *token = strtok(cmd_copy, " "); /* Tokenize cmd_copy (e.g. "cd dir": 'cd' -> arg[0], 'dir' -> arg[1])  */

  while (token != NULL && i < 15) { /* Work until token is NULL and there's less than 15 token (16th one is for NULL) */
    arg[i] = token; /* Save token to correct place in arg[] */
    i = i + 1; /* Increment i for next token */
    token = strtok(NULL, " "); /* Get new token for next loop; return NULL if no more tokens  */               
  } 
  
  arg[i] = NULL; /* Save NULL to the last token */
  
  if (!arg[0]) return 0; /* If no command entered, return 0 */
  
  /*
   * Some commands don't use args, some use 1 or 2 args.
   * If a command doesn't use args, parser runs the command.
   * If uses 1 arg, parser checks for 1 arg and runs the command with the arg.
   * If uses 2 args, parser checks for 2 args, and runs the command with args.
   */
  
  if (strcmp(arg[0], "cat") == 0 && arg[1]) {
    cmd_cat(arg[1]);
  } else if (strcmp(arg[0], "cd") == 0 && arg[1]) {
    cmd_cd(arg[1]);
  } else if (strcmp(arg[0], "cls") == 0) {
    cmd_cls();
  } else if (strcmp(arg[0], "echo") == 0 && arg[1]) {
    cmd_echo(arg[1]);
  } else if (strcmp(arg[0], "grep") == 0 && arg[1] && arg[2]) {
    cmd_grep(arg[1], arg[2]);
  } else if (strcmp(arg[0], "ls") == 0) {
    cmd_ls(arg[1]);
  } else if (strcmp(arg[0], "mkdir") == 0 && arg[1]) {
    cmd_mkdir(arg[1]);
  } else if (strcmp(arg[0], "touch") == 0 && arg[1]) {
    cmd_touch(arg[1]);
  } else if (strcmp(arg[0], "pwd") == 0) {
    cmd_pwd();
  } else if (strcmp(arg[0], "rm") == 0 && arg[1]) {
    cmd_rm(arg[1]);
  } else if (strcmp(arg[0], "run") == 0 && arg[1]) {
    cmd_run(arg[1]);
  } else if (strcmp(arg[0], "help") == 0) {
    cmd_help();
  } else {
    printf("%s%s: Command not found.%s\n", red, arg[0], reset);
  }
  
  return 0;
}
