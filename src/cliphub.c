#include "cliphub.h"
#include <stdlib.h>

Clipboard *clipboard_init(int size) {
  /*
   * Make sure that the clipboard history is created and is not larger than the
   * maximum size. If the clipboard history is larger than the maximum size, the
   * oldest entries should be removed.
   */
}

void store(Clipboard *clipboard, char *path) {}
