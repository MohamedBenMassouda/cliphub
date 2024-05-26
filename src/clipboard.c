#include "clipboard.h"
#include <stdlib.h>
#include <string.h>

Clipboard *clipboard_init(int size) {
  Clipboard *clipboard = (Clipboard *)malloc(sizeof(Clipboard));

  clipboard->text = (char *)malloc(size * sizeof(char));
  clipboard->length = 0;

  return clipboard;
}

void clipboard_destroy(Clipboard *clipboard) {
  free(clipboard->text);
  free(clipboard);
}

void store(Clipboard *clipboard, char *path) {}
