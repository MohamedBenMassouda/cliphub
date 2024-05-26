#include <stdio.h>

#include "cliphub.h"
#include "utils.h"
#include <unistd.h>

int main() {
  printf("%b", file_exists(CLIPHUB_PATH));

  char buffer[1024];

  // Read from standard input until EOF
  while (fgets(buffer, sizeof(buffer), stdin) != NULL) {
    // Process the input
    printf("Read: %s", buffer);
  }

  return 0;
}
