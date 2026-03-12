/*
 * pwd.c
 * MSH - Micha1207's Shell program.
 *
 * pwd - print working (current) directory.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Mar 9, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>
#include <unistd.h>

#include "pwd.h"

/*
 * Print working directory path.
 * Returns 0 on success, 1 if cannot
 * reat working directory.
 */
int cmd_pwd(){
  char cwd[1024];

  if (getcwd(cwd, sizeof(cwd)) != NULL){
    printf("%s\n", cwd);
  } else {
    perror("getcwd");
    return 1;
  }
  
  return 0;
}
