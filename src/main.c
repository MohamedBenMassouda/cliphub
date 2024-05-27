#include <stdio.h>

#include "cliphub.h"
#include "utils.h"
#include <stdlib.h>
#include <unistd.h>

bool data_is_piped() {
  char buffer[1024];

  // Read from standard input until EOF
  while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
    // Process the input
    printf("Read: %s", buffer);
  }

  return 0;
}

int main() {
  history_init(100);

  Clipboard *clipboard = (Clipboard *)malloc(sizeof(Clipboard));
  clipboard->text = (char *)malloc(100);

  clipboard->text = "Hello, world!";
  clipboard->length = 13;

  store(clipboard);
}
