/*
 * echo.c
 * MSH - Micha1207's Shell program.
 *
 * echo - echo text or $HOME\$PATH environment variables
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Mar 8, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>
#include <stdlib.h>

#include "echo.h"

/*
 * Echo text or some environment variables.
 * Argument input is an array, each word must be in
 * a new element. In MSH's parser, element 0
 * is the command name, while its arguments (here: text)
 * starts on element 1.
 * If no arguments, print a new line. Otherwise, print
 * every single word or if system variable (starting with '$')
 * detected, get its value and print it.
 * Returns 0 on success.
 */
int cmd_echo(char *input[]){
  int i;
  for (i = 1; input[i] != NULL; i++){
    if (input[i][0] == '$'){
      char *env_var_name = &input[i][1];
      char *value = getenv(env_var_name);
      if (value) printf("%s ", value);
    } else {
      printf("%s ", input[i]);
    }
  }
  printf("\n");

  return 0;
}
