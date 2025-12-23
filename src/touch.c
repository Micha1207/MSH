/*
 * touch.c
 * Make a file or update it's time.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Dec 22, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>

// Include header file (form include/)
#include "touch.h"

int cmd_touch(const char *file){ // Function for touch command.
  FILE *fp = fopen(file, "w"); // Make a pointer for requested file.

  if (!fp){          // If there's error opening the file:
    perror("fopen"); // - print an error,
    return 1;        // - return error code.
  }
  
  fclose(fp); // Close the file.

  return 0; // Return success code.
}
