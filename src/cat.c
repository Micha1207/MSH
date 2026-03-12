/*
 * cat.c
 * MSH - Micha1207's Shell program.
 *
 * cat - print file contents
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Mar 12, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>

#include "cat.h"

/*
 * Print contents of the file to stdout.
 * Argument filename is path to file.
 * Returns 0 on success, 1 if error when the file
 * cannot be opened.
 */
int cmd_cat(const char filename[]){
  char line[1024];
  FILE *fp = fopen(filename, "r");
  
  if (!fp){
    perror(filename);
    return 1;
  }

  while (fgets(line, sizeof(line), fp)){
    printf("%s", line);
  }

  fclose (fp);
  return 0;
}
