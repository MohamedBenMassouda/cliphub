#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "cliphub.h"
#include "utils.h"

bool data_is_piped() { return !isatty(fileno(stdin)); }

int main() {
  char buffer[1024];
  if (data_is_piped()) {
    // Read from standard input until EOF
    if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
      Clipboard *clipboard = clipboard_init(buffer);

      store(clipboard);
      printf("Stored: %s", buffer);

      free(clipboard);
    }
  }

  return 0;
}

