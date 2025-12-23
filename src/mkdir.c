/*
 * mkdir.c
 * Make a new directory.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Dec 22, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

// Include header file (from include/)
#include "mkdir.h"

int cmd_mkdir(const char *name){ // Function for mkdir command.
  mkdir(name, 0777); // Make a directory (777 permission).

  return 0; // return success code.
}
