/*
 * mkdir.c
 * MSH - Micha1207's Shell program.
 *
 * mkdir - make a directory
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Mar 9, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>

#include "mkdir.h"

/*
 * Make a directory.
 * Returns 0 on success.
 */
int cmd_mkdir(const char *name){
  if (mkdir(name, 0777) != 0){
    perror("mkdir");
    return 1;
  }
  
  return 0;
}
