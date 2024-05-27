#define CLIPHUB_PATH "~/.local/share/cliphub"
#define CLIPHUB_SIZE 100
#define MAX_CLIPHUB_SIZE 100

typedef struct {
  char *text;
  int length;
} Clipboard;

typedef struct {
  Clipboard *clipboards;
  int size;
  int last_index;
} History;

Clipboard *clipboard_init();
History *history_init();
void clipboard_destroy(Clipboard *clipboard);
void store(Clipboard *clipboard);
