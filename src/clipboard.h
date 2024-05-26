#define CLIPBOARD_PATH "~/.local/share/clipboard"
#define CLIPBOARD_SIZE 100
#define MAX_CLIPBOARD_SIZE 100
#define MAX_STRING_SIZE 100

typedef struct {
  char *text;
  int length;
} Clipboard;

Clipboard *clipboard_init(int size);
void clipboard_destroy(Clipboard *clipboard);
void clipboard_store(Clipboard *clipboard);
