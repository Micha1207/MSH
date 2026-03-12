/*
 * ls.c
 * MSH - Micha1207's Shell program.
 *
 * ls - list files and directories in directory.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Mar 9, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#define _DEFAULT_SOURCE 
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <dirent.h>

#include "ls.h"
#include "colors.h"

/*
 * List objects in directory.
 * If path isn't specified, set it to current working
 * directory, oterwise list objects in specified path.
 * Get names of all objects in directory, color them
 * according to type (blue for directories, white for
 * files, green for other). Hidden objects (starting with '.')
 * are ignored and not printed.
 * Returns 0 on success, 1 if cannot open directory.
 */
int cmd_ls(const char *input_path){
  const char *path = "";
  DIR *dir;
  struct dirent *entry;
  
  if (input_path != NULL){
    path = input_path;
  } else {
    path = ".";
  }  
  
  dir = opendir(path);
  
  if (!dir){
    perror(path);
    return 1;
  }
  
  while ((entry = readdir (dir)) != NULL){
    if (entry->d_name[0] == '.')
      continue;
    if (entry->d_type == DT_DIR){
      printf ("%s%s/%s\n", blue, entry->d_name, reset);
    } else if (entry->d_type == DT_REG){
      printf ("%s%s%s\n", white, entry->d_name, reset);
    } else {
      printf ("%s%s%s\n", green, entry->d_name, reset);
    }
  }

  closedir (dir);
  return 0;
}
