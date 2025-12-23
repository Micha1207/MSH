/*
 * run.c
 * Run commands from system's $PATH variable.
 *
 * Author:  Micha1207
 * Project: MSH (https://github.com/Micha1207/MSH)
 * Date:    Dec 22, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

// Include header file (from include/)
#include "run.h"

int cmd_run(char *args[]) {
  pid_t pid = fork();
  if (pid == 0) {
    execvp(args[0], args);
    perror("execvp");
    _exit(1);
  } else if (pid > 0) {
    int status;
    waitpid(pid, &status, 0);
    return WIFEXITED(status) ? WEXITSTATUS(status) : 1;
  } else {
    perror("fork");
    return 1;
  }
}
