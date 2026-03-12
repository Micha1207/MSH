/*
 * cd.c
 * MSH - Micha1207's Shell program.
 *
 * cd - change directory
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Mar 12, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>

#include "cd.h"

/*
 * Change directory.
 * Argument path is the directory's path.
 * If no path entered or it's ~, get $HOME
 * environment variable and change directory into it.
 * Returns 0 on success, 1 if cannot change
 * directory, 2 if $HOME is not set.
 */
int cmd_cd (const char *path){
  const char *final_path = path;

  if (path == NULL || strcmp(path, "~") == 0){
    final_path = getenv("HOME");
    if (!final_path){
      perror("$HOME");
      return 2;
    }
  }

  if (chdir(final_path) != 0){
    perror ("cd");
    return 1;
  }

  return 0;
}
