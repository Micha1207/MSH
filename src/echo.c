/*
 * echo.c
 * Print entered text or some system's environmental variables.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Dec 23, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// Include header file (from include/)
#include "echo.h"

int cmd_echo(char input[]){ // Function for echo command.
  char *output = "";         // Constant for text that will be printed.
  
  if (strcmp(input, "$HOME") == 0){        // If input is $HOME:
    output = getenv("HOME");               // - read user's home directory (from env. variable $HOME), 
  } else if (strcmp(input, "$PATH") == 0){ // If input is $PATH: 
    output = getenv("PATH");               // - read system's $PATH,
  } else {                                 // If it's any other text:
    output = input;                        // - print it.
  }
  
  printf("%s\n", output); // Print output.

  return 0; /* Return sucess code */
}
