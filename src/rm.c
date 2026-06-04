/*
 * rm.c
 * MSH - Micha1207's Shell program.
 *
 * Remove file or directory.
 * Return 0 on success, 1 if cannot remove
 * object.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    June 4, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>

#include "rm.h"

int cmd_rm(const char *target){
  if (remove(target) != 0){
    perror ("remove");
    return 1;
  }
  
  return 0;
}
