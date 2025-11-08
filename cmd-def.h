/*
 * cmd-def.h
 * Define MSH commands.
 * This is part of the Micha1207's Shell program (MSH)
 *
 * Author:  Micha1207
 * Date:    Nov 8, 2025
 * License: GNU GPL v3 (full license in LICENSE file)
 * This program comes with NO WARRANTY; to the extent permitted by law.
 */
#ifndef CMD_DEF_H
#define CMD_DEF_H

#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/wait.h>

#include "colors.h"

int cmd_cat(const char *file){
  FILE *fp = fopen(file, "r");

  if (!fp){
    perror(file);
    return 1;
  }
  char buf[128];

  while (fgets(buf, sizeof(buf), fp)){
    fputs(buf, stdout);
  }

  fclose(fp);

  return 0;
}


int cmd_cd(const char *path){
  const char *final_path = path;
  
  if (strcmp(path, "~") == 0){
    final_path = getenv("HOME");
    if (!final_path){
      fprintf(stderr, "HOME system environment variable not set. \n");
      return 1;
    }
  }

  if (chdir(final_path) != 0){
    perror("cd");
    return 1;
  }
  
  return 0;
}

int cmd_cls(){
  printf("\033[H\033[J");

  return 0;
}

int cmd_echo(const char *text){
  printf("%s\n", text);

  return 0;
}

int cmd_grep(const char *pattern, const char *file){
  FILE *fp = fopen(file, "r");

  if (fp == NULL){
    perror("grep");
    return 1;
  }

  char line[1024];
  while (fgets(line, sizeof(line), fp)){
    if (strstr(line, pattern)){
      printf("%s", line);
    }
  }

  fclose(fp);

  return 0;
}

int cmd_ls(const char *path) {
  const char *real_path = (path && path[0]) ? path : ".";

  DIR *dir = opendir(real_path);
  if (!dir) {
    perror("ls");
    return 1;
  }

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
    if (entry->d_name[0] == '.') continue;

    if (entry->d_type == DT_DIR)
      printf("%s%s/%s\n", reset, entry->d_name, reset);
    else if (entry->d_type == DT_REG)
      printf("%s%s %s\n", green, entry->d_name, reset);
    else
      printf("%s%s %s\n", yellow, entry->d_name, reset);
  }

  closedir(dir);
  return 0;
}

int cmd_mkdir(const char *name){
  mkdir(name, 0777);

  return 0;
}

int cmd_touch(const char *file){
  FILE *fp = fopen(file, "w");

  if (!fp){
    perror("fopen");
    return 1;
  }
  
  fclose(fp);

  return 0;
}

int cmd_pwd(){
  char cwd[1024];

  if (getcwd(cwd, sizeof(cwd)) != NULL){
    printf("%s\n", cwd);
  } else {
    perror("getcwd");
    return 1;
  }

  return 0;
}

int cmd_rm(const char *target){
  if (remove(target) != 0){
    perror("remove");
    return 1;
  }

  return 0;
}

int cmd_run(const char *cmd) {
    pid_t pid = fork();
    if (pid == 0) {
        char *args[] = { (char *)cmd, NULL };
        execvp(cmd, args);
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

int cmd_help(){
  printf("cat <file>            - show contents of <file>\n");
  printf("cd <path/to/dir>      - change directory to <path/to/dir>\n");
  printf("cls                   - clear\n");
  printf("echo <text>           - echo <text> in prompt\n");
  printf("grep <pattern> <file> - look for <pattern> in <file>\n");
  printf("ls                    - list contents of current dir\n");
  printf("mkdir <dir>           - make directory <dir>\n");
  printf("touch <file>          - make file <file>\n");
  printf("pwd                   - print working directory\n");
  printf("rm <name>             - remove file or directory <name>\n");
  printf("run <command>         - run <command> from $PATH\n");

  return 0;
}

#endif /* CMD_DEF_H */
