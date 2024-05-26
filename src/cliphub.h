#define CLIPHUB_PATH "~/.local/share/cliphub"
#define CLIPHUB_SIZE 100
#define MAX_CLIPHUB_SIZE 100

typedef struct {
  char *text;
  int length;
} Clipboard;

Clipboard *clipboard_init(int size);
void clipboard_destroy(Clipboard *clipboard);
void store(Clipboard *clipboard);
