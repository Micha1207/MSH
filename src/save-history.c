/*
 * save-history.c
 * MSH - Micha1207's Shell program.
 *
 * Save entered command to history file (defined in src/main.c)
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Mar 8, 2026
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>

/*
 * This function saves entered command string to specified
 * shell commands' history file.
 * Return 0 on success.
 */
int save_history(char *cmd, char *filename){
  FILE *fp = fopen(filename, "a");

  fprintf(fp, "%s\n", cmd);

  fclose(fp);
  return 0;
}
