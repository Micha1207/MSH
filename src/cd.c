/*
 * cd.c
 * Change directory.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Dec 22, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

// Include the header file (from include/).
#include "cd.h"

int cmd_cd(const char *path){    // Function for cd command.
  const char *final_path = path; // Make a pointer for the final path (explained below)
  
  if (path == NULL || strcmp(path, "~") == 0){  // If path is '~' or there's no path specified at all, then:
    final_path = getenv("HOME");                // - read user's home directory, but
    if (!final_path){                           // - if HOME env. variable is not set:
      fprintf(stderr, "cd: $HOME not set.");    //   - print an error
      return 1;                                 //   - return error code.
    }
  }

  if (chdir(final_path) != 0){   // If cannot change path:
    perror("cd");                // -print an error
    return 1;                    // -return error code
  }
  
  return 0; // Return success code 
}
