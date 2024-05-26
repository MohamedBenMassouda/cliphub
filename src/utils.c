#include "utils.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

bool execute_command(char *command) {
  FILE *fp;
  char path[1035];

  /* Open the command for reading. */
  fp = popen(command, "r");
  if (fp == NULL) {
    printf("Failed to run command\n");
    return false;
  }

  /* Read the output a line at a time - output it. */
  while (fgets(path, sizeof(path) - 1, fp) != NULL) {
    printf("%s", path);
  }

  /* close */
  pclose(fp);
  return true;
}

bool file_exists(const char *filename) {
  if (filename == NULL) {
    return false;
  }

  if (filename[0] == '~') {
    // Expand the tilde to the home directory (if it exists
    const char *home = getenv("HOME");
    if (home == NULL) {
      printf("HOME environment variable not set\n");
      return false;
    }

    char *expanded = malloc(strlen(home) + strlen(filename) + 1);

    strcpy(expanded, home);

    if (strlen(filename) > 1) {
      strcat(expanded, filename + 1);
    }

    filename = expanded;
  }

  FILE *file;
  if ((file = fopen(filename, "r"))) {
    fclose(file);
    return true;
  }

  printf("File does not exist: %s\n", filename);

  printf("Creating file: %s\n", filename);

  FILE *f = fopen(filename, "w");

  if (f == NULL) {
    printf("Error opening file!\n");
    return false;
  }

  fclose(f);
  return true;
}

void smart_log(const char *message, bool notify) {
  FILE *f = fopen("cliphub.log", "a");
  if (f == NULL) {
    printf("Error opening file!\n");
    return;
  }

  fprintf(f, "%s\n", message);
  fclose(f);

  if (notify) {
    char command[1024];
    sprintf(command, "notify-send \"%s\"", message);
    execute_command(command);
  }
}
