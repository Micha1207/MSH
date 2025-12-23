/*
 * help.c
 * Print MSH command usage.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Dec 22, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>

// Include header file (from include/)
#include "help.h"

int cmd_help(){ // Function for help command.
  // Print help text.
  printf("cat <file>            - show contents of <file>\n");
  printf("cd <path/to/dir>      - change directory to <path/to/dir>\n");
  printf("cls                   - clear\n");
  printf("echo <text>           - echo <text> in prompt\n");
  printf("grep <pattern> <file> - look for <pattern> in <file>\n");
  printf("ls                    - list contents of current dir\n");
  printf("mkdir <dir>           - make directory <dir>\n");
  printf("touch <file>          - make file <file>\n");
  printf("pwd                   - print working directory\n");
  printf("rm <name>             - remove file or directory <name>\n");
  printf("run <command>         - run <command> from $PATH\n");

  return 0;
}
