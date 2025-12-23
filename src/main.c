/*
 * main.c
 * MSH - Micha1207 Shell program.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Dec 23, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
*/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Include necessary files
#include "cmd-parser.h"
#include "colors.h"

// Define variables and constants.
char cmd[512];             // Buffer for commands
#define PROMPT_COLOR cyan  // Shell prompt color
#define DEF_COLOR    reset // Default color (white)

// Print shell prompt and read the command.
int sh_prompt(){
  printf("%s$ %s", PROMPT_COLOR, DEF_COLOR); // Print shell prompt.

  if (!fgets(cmd, sizeof(cmd), stdin)){ // If there's anything on stdin (input):
    printf("\n");                       // - print newline character before closing pogram,
    exit(0);                            // - close the program.
  }

  cmd[strcspn(cmd, "\n")] = 0; // Replace newline with string-end character

  return 0;
}

int main(){ // Main function
  printf("To see available commands type: help\n"); // Print help message
  
  while (sh_prompt() == 0){        // If sh_prompt() ran successfully:
    if (strcmp(cmd, "exit") == 0){ // - check if command is exit,
      exit(0);                     // - if it is: exit the shell,
    } else {                       // if command isn't exit:
      runcmd(cmd);                 // - run it.
    }
  }
  
  return 0; // Return success code.
}
