/*
 * ls.c
 * List content of working directory.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Dec 23, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#define _DEFAULT_SOURCE
#include <stdio.h>
#include <dirent.h>

// Include header file (from include/)
#include "ls.h"

// Include color definitions.
#include "colors.h"

int cmd_ls(const char *user_path) { // Function for ls command.
  const char *path; // Make a pointer for path.
  
  if (user_path != NULL) { // If user didn't specify path:
    path = user_path;      // - set the path to user specified one,
  } else {                 // Else:
    path = ".";            // - set path to working directory.
  }
  
  DIR *dir = opendir(path); // Open the path.
  
  if (!dir) {     // If the path doesn't exist:
    perror("ls"); // - print an error,
    return 1;     // - return error code.
  }
  
  struct dirent *entry;
  
  while ((entry = readdir(dir)) != NULL) {               // Loop for reading directory:
    if (entry->d_name[0] == '.') continue;               // - ignore all files starting by '.' (hidden files),
    
    if (entry->d_type == DT_DIR) {                       // if object in directory is directory: 
      printf("%s%s/%s\n", blue, entry->d_name, reset);   // - print it's name with blue color,
    } else if (entry->d_type == DT_REG) {                // if it's a file:
      printf("%s%s %s\n", white, entry->d_name, reset);  // - print it's name with white,
    } else {                                             // if it's anything else:
      printf("%s%s %s\n", green, entry->d_name, reset); // - print it too with green.
    }
  }
  
  closedir(dir);
  return 0;
}
