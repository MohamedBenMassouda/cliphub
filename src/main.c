#include <stdio.h>

#include "utils.h"
#include <unistd.h>

int main() {

  char buffer[1024];

  // Read from standard input until EOF
  while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
    // Process the input
    printf("Read: %s", buffer);
  }

  return 0;
}
