/*
 * main.c
 * MSH - Micha1207's Shell program.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    June 3, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#include "parser.h"
#include "sys-info.h"
#include "colors.h"

int main(){
  printf("%sTo see available commands type: help%s\n", RED, RESET);

  static int exit_status = 0;
  size_t cmd_size = 256;
  char cmd[cmd_size], username[64],
    hostname[128], cwd[1024];
  
  sys_info(username, hostname);
  
  while (1){
    getcwd(cwd, 1024);
    
    printf("%s[%s%s%s@%s%s: %s%s%s](%s%d%s)%s$%s ", BLUE, GREEN, username, RED, GREEN,
	   hostname, CYAN, cwd, BLUE, YELLOW, exit_status, BLUE, MAGENTA, RESET);
    
    if (!fgets(cmd, cmd_size, stdin)) printf("\n");
    
    cmd[strcspn(cmd, "\n")] = '\0';

    if (strcmp(cmd, "exit") == 0) return 0;
    else exit_status = parser(cmd, cmd_size);
  }
  
  return 0;
}
