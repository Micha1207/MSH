/*
 * main.c
 * MSH - Micha1207 Shell program.
 *
 * Author:  Micha1207
 * Date:    Nov 8, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
*/
#include <stdio.h> 
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "cmd-parser.c"
#include "colors.h"

/* Define variables and constants. */
char cmd[512];             /* Buffer for commands */
#define PROMPT_COLOR cyan  /* Shell prompt color   */
#define DEF_COLOR    reset /* Default color (white) */

/* Print shell prompt and read the command. */
int sh_prompt(){
  printf("%s$> %s", PROMPT_COLOR, DEF_COLOR); /* Print CMD prompt. */

  if (!fgets(cmd, sizeof(cmd), stdin)){ /* Get command from stdin */
    printf("\n");
    exit(0);
  }

  cmd[strcspn(cmd, "\n")] = 0; /* Replace newline with string-end character */

  return 0;
}

/* Main function:
 * Run sh_prompt() and read command
 * If command is exit, stop the shell.
 * If command isn't exit than run it (using runcmd() from `cmd-parser.c`)
 */
int main(){
  while (sh_prompt() == 0){
    if (strcmp(cmd, "exit") == 0){ 
      exit(0);
    } else {
      runcmd(cmd);
    }
  }
  
  return 0;
}
