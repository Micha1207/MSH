/*
 * cmd-parser.c
 * Parse commands and run them.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Dec 22, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>
#include <string.h>

// Include header files for commands (from include/)
#include "cat.h"
#include "cd.h"
#include "cls.h"
#include "echo.h"
#include "grep.h"
#include "help.h"
#include "ls.h"
#include "mkdir.h"
#include "pwd.h"
#include "rm.h"
#include "run.h"
#include "touch.h"

#include "cmd-parser.h"
#include "colors.h"

int runcmd(const char *cmd) { // Function to run commands.
  char cmd_copy[512];                       // Buffer for cmd copy.
  strncpy(cmd_copy, cmd, sizeof(cmd_copy)); // Copy cmd into cmd_copy
  cmd_copy[sizeof(cmd_copy) - 1] = '\0';    // Make sure string always ends with '\0' (NULL) characher
  
  char *arg[16]; // Array for args 
  int i = 0;     // Index for arg[] 
  char *token = strtok(cmd_copy, " "); // Tokenize cmd_copy (e.g. "cd dir": 'cd' -> arg[0], 'dir' -> arg[1])

  while (token != NULL && i < 15) { // While token isn't NULL and there's less than 15 tokens (16th one is for NULL):
    arg[i] = token;                 // - save token to it's place in arg[],
    i = i + 1;                      // - increment i for next token,
    token = strtok(NULL, " ");      // - get new token; return NULL if no more tokens.             
  } 
  
  arg[i] = NULL; // Save NULL to the last token
  
  if (!arg[0]) return 0; // If there are no arguments, return 0
  
  /*
   * Below code detects commands and runs them with their arguments. 
   * If it's shell's command, it funs it, but if it's not - looks for it
   * in system's PATH env. variavle, and executes it. If command isn't even there,
   * program returns an error (see src/run.c).
   */
  
  if (strcmp(arg[0], "cat") == 0 && arg[1]) {
    cmd_cat(arg[1]);
  } else if (strcmp(arg[0], "cd") == 0 && arg[1]) {
    cmd_cd(arg[1]);
  } else if (strcmp(arg[0], "cls") == 0 || strcmp(arg[0], "clear") == 0) {
    cmd_cls();
  } else if (strcmp(arg[0], "echo") == 0 && arg[1]) {
    cmd_echo(arg[1]);
  } else if (strcmp(arg[0], "grep") == 0 && arg[1] && arg[2) {
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
  } else if (strcmp(arg[0], "help") == 0) {
    cmd_help();
  } else if (strcmp(arg[0], "run") == 0) {
    cmd_run(&arg[1]); // Because of that run is arg[0], program is arg[1]. Since we run the program, pass the arg[1] to cmd_run().
  } else {
    cmd_run(arg); // And here program is arg[0]. Pass it to cmd_run().
  }
  
  return 0; // Return success code.
}
