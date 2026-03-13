/*
 * main.c
 * MSH - Micha1207's Shell program.
 *
 * Author:  Micha1207
 * Project: MTP (https://github.com/Micha1207/MTP)
 * Date:    Mar 9, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#define _DEFAULT_SOURCE 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "parser.h"
#include "save-history.h"
#include "colors.h"
#include "clear.h"

/* Gets $HOME and creates this file to save entered commands in it. */
#define HISTORY_FILE ".msh_history"

#define print_prompt() printf("%s[%s%s@%s: %s%s%s]%s$ %s", blue, green, username, hostname, cyan, dir, blue, magenta, reset)

char cmd[512];

/*
 * This function makes a prompt and get's command
 * with all arguments.
 * Returns 0 if success.
 */
int sh_prompt(char *username, char *hostname, char *dir){
  print_prompt();
  if (!fgets(cmd, sizeof(cmd), stdin)){
    printf("\n");
    exit(0);
  }
  
  cmd[strcspn(cmd, "\n")] = '\0';
  
  return 0;
}

int main (){
  printf("%sTo see available commands type: help%s\n", red, reset);
  
  const char *homedir = getenv("HOME");
  char *user = getenv("USER");
  char hostname[256];
  gethostname(hostname, sizeof(hostname));
  
  char homedir_copy[128];
  strncpy(homedir_copy, homedir, sizeof(homedir_copy));
  char *hist_file = strcat(homedir_copy, "/.msh_history");
  
  while (1){
    char cwd[1024];
    getcwd(cwd, sizeof(cwd));
    if (sh_prompt(user, hostname, cwd) == 0){
      if (strcmp(cmd, "exit") == 0){
	exit(0);
      } else {
	save_history(cmd, hist_file);
	runcmd(cmd);
      }
    }
  }
  
  return 0;
}
