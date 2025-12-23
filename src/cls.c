/*
 * cls.c
 * Clear terminal screen.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Dec 13, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>

// Include the header file (from include/).
#include "cls.h"

int cmd_cls(){            // Function for clear command. 
  printf("\033[H\033[J"); // Clear terminal's screen (writes ANSI clear)

  return 0; // Return success code.
}
