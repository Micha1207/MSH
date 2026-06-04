/*
 * sys-info.c
 *
 * Resolve system information, such as username,
 * hostname or home directory.
 * Argument 'username' is a pointer to string, size 64, that stores
 * retreived username, and 'hostname', is a pointer to string, size 128,
 * that stores the hostname.
 * Returns 0 on success.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    June 4, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#include "sys-info.h"

int sys_info(char username[64], char hostname[128]){
  char *username_ptr = getenv("USER");
  if (username_ptr != NULL){
    strncpy(username, username_ptr, 63);
  } else {
     strncpy(username, "I have no name!", 63);
  }
  
  gethostname(hostname, 128);

  return 0;
}
