#define LEN 4

extern int front;
extern int tail;
extern int size;
extern int arr[LEN];

void in_queue(char input);
char out_queue();
int is_full();
int is_empty();
int queue_size();
