/*
 * grep.c
 * Search desired pattern in file.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Dec 22, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
 
#include <stdio.h>
#include <string.h>

// Include the header file (from include/)
#include "grep.h"
 
int cmd_grep(const char *pattern, const char *file){ // Function for grep command.
  FILE *fp = fopen(file, "r");  // Make a pointer for the file.

  if (fp == NULL){  // If requested file doesn't exist:
    perror("grep"); // - print an error,
    return 1;       // - return error code.
  }

  char line[1024]; // Make a buffer for file's line.
  
  while (fgets(line, sizeof(line), fp)){ // While the program can get a file's line:
    if (strstr(line, pattern)){          // - if anything in currently checked line matches pattern:
      printf("%s", line);                // - print that line.
    }
  }

  fclose(fp); // close the file.

  return 0; // Return success code.
}
