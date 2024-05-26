#include "utils.h"
#include <stdbool.h>
#include <stdio.h>

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
