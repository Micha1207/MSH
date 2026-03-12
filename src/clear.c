/*
 * clear.c
 * MSH - Micha1207's Shell program.
 *
 * clear - clear terminal window
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Mar 9, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>

#include "clear.h"

/*
 * Clear terminal.
 * Returns 0 on success.
 */
int cmd_clear(){
  printf("\033[H\033[J");

  return 0;
}
