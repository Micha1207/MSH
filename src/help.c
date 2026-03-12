/*
 * help.c
 * MSH - Micha1207's Shell program.
 *
 * help - print help.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Mar 9, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>

#include "help.h"

/*
 * Print MSH help.
 * Returns 0 on success.
 */
int cmd_help(){
  printf("MSH by Micha1207.\n");
  printf("Version: 2.0 r2\n");
  printf("Licensed under GNU General Public License, version 3.\n\n");

  printf("cat <file>            - show contents of file\n");
  printf("cd <path/to/dir>      - change directory\n");
  printf("cls, clear            - clear terminal\n");
  printf("echo <text>           - echo text, $PATH or $HOME\n");
  printf("ls, dir               - list objects in current directory\n");
  printf("mkdir <dir>           - make directory\n");
  printf("pwd                   - print working directory\n");
  printf("rm <name>             - remove file or directory\n");
  printf("run <command>         - run command from $PATH\n");
  printf("touch <file>          - create file or update it's time\n");
  printf("<command>             - run any command from $PATH\n");

  return 0;
}
