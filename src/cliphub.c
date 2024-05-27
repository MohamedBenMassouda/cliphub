#include "cliphub.h"
#include "utils.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

History *history_init(int size) {
  printf("Initializing history with size %d\n", size);
  History *history = malloc(sizeof(History));
  history->clipboards = malloc(size * sizeof(Clipboard));
  history->size = size;

  return history;
}

History *get_history() {
  FILE *file = open_file(CLIPHUB_PATH, "r");

  if (!file) {
    smart_log("Could not open file", true);
    exit(1);
  }

  char *line = NULL;
  size_t len = 0;
  ssize_t read;

  History *history = history_init(CLIPHUB_SIZE);

  int i = 0;
  while ((read = getline(&line, &len, file)) != -1) {
    Clipboard *clipboard = malloc(sizeof(Clipboard));
    clipboard->text = malloc(strlen(line) + 1);
    strcpy(clipboard->text, line);
    clipboard->length = strlen(line);

    history->clipboards[i] = *clipboard;

    if (clipboard->text == NULL) {
      history->last_index = i;
    }

    i++;
  }

  fclose(file);
  return history;
}

Clipboard *clipboard_init() {
  /*
   * Make sure that the clipboard history is created and is not larger than the
   * maximum size. If the clipboard history is larger than the maximum size, the
   * oldest entries should be removed.
   */
  bool exists = file_exists(CLIPHUB_PATH);

  if (!exists) {
    smart_log("Something went wrong", true);
    exit(1);
  }

  History *history = get_history();

  for (int i = 0; i < history->size; i++) {
    Clipboard *clipboard = &history->clipboards[i];

    if (clipboard->text == NULL) {
      continue;
    }

    printf("%s", clipboard->text);
  }

  return NULL;
}

void store(Clipboard *clipboard) {
  FILE *file = open_file(CLIPHUB_PATH, "a");

  if (!file) {
    smart_log("Could not open file", true);
    exit(1);
  }

  fprintf(file, "%s", clipboard->text);
  fprintf(file, "\n");
  fclose(file);

  smart_log("Stored clipboard", true);
}
