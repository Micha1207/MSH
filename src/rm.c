/*
 * rm.c
 * Remove file or directory.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Dec 22, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>

// Include header file (form include/)
#include "rm.h"

int cmd_rm(const char *target){ // Function for rm command.
  if (remove(target) != 0){ // Remove target. If it returns an error:
    perror("remove");       // - print it,
    return 1;               // - return error code.
  }

  return 0; // Return success code.
}
