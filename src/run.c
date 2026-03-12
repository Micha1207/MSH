# 1 "src/run.c"
# 11 "src/run.c"
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>


#include "run.h"

int cmd_run (char *args[]){
  pid_t pid = fork();
  if (pid == 0){
    execvp(args[0], args);
    perror(args[0]);
    _exit (1);
  } else if (pid > 0){
    int status;
    waitpid (pid, &status, 0);
    return WIFEXITED (status) ? WEXITSTATUS (status) : 1;
  } else {
    perror ("fork");
    return 1;
  }
}
