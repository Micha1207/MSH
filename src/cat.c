/*
 * cat.c
 * Concatenate file and print it's content.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Dec 22, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>

// Include the header file (from include/)
#include "cat.h"

int cmd_cat(const char file_name[]){ // Function for cat command.
  FILE *fp = fopen(file_name, "r");  // Make a pointer for file 

  if (!fp){                          // If the file doesn't exist:
    perror(file_name);               // - print an error
    return 1;                        // - return error code 1
  }
  
  char buf[1024];                    // Make a buffer for file's line

  while (fgets(buf, sizeof(buf), fp)){  // Read each line of the file
    fputs(buf, stdout);                 // and then print it
  }

  fclose(fp);                        // Close the file

  return 0;   // Return success code.
}
