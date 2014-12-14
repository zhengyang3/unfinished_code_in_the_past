struct list {
	struct node head_node;
};

struct node {
	int data;
	struct node * prev;
	struct node * next;
};

struct node * node_malloc(int);
struct list * list_malloc(void);
void list_tail_add(struct list *, int);
void list_head_add(struct list *, int);
void list_tail_del(struct list *);
void list_head_del(struct list *);

void list_del_by_data(struct list *, int)
void list_del_by_pos(struct list *, int)

int list_size(struct list *);

void list_for_each(struct list *);

