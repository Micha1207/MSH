/*
 * touch.c
 * MSH - Micha1207's Shell program.
 *
 * touch - create new file or update its time
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Mar 8, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>

#include "touch.h"

/*
 * Create a new file or update its time.
 * Returns 0 on success, 1 if error.
 */
int cmd_touch(const char *file){
  FILE *fp = fopen(file, "w");

  if (!fp){
    perror("fopen");
    return 1;
  }
  
  fclose(fp);
  
  return 0;
}
