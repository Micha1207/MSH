/*
 * pwd.c
 * Print working directory.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Dec 22, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>
#include <unistd.h>

// Include header file (form include/)
#include "pwd.h"

int cmd_pwd(){ // Function for pwd command.
  char cwd[1024]; // Make a buffer for directory name.

  if (getcwd(cwd, sizeof(cwd)) != NULL){ // If program can get it's working directory:
    printf("%s\n", cwd);                 // - print it,
  } else {                               // if ti can't:
    perror("getcwd");                    // - print an error,
    return 1;                            // - return error code.
  }

  return 0; // Return success code.
}
