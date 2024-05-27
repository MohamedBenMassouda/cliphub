#include <stdbool.h>
#include <stdio.h>

bool execute_command(char *command);
bool file_exists(const char *filename);
void smart_log(const char *message, bool notify);
FILE *open_file(const char *filename, const char *mode);
