#include "list.h"

struct node * node_malloc(int _data)
{
	struct node * node = (struct node *)malloc(sizeof(struct node));
	if (node == NULL) {
		fprintf(stderr, "malloc node err!\n");
		exit(1);
	}

	node->data = _data;
	node->next = node;
	node->prev = node;

	return node;
}

struct list * list_malloc(void)
{
	struct list * list = (struct list *)malloc(sizeof(struct list));

	list->head_node.data = 0;
	list->head_node.next = list->head_node;
	list->head_node.prev = list->head_node;

	return list;
}

void list_tail_add(struct list * _list, int _data)
{
	struct node * node = node_malloc(_data);

	node->next = _list->head_node;
	node->prev = _list->head_node->prev;

	node->next->prev = node;
	node->prev->next = node;

	return;
}

void list_head_add(struct list * _list, int _data)
{
	struct node * node = node_malloc(_data);	
	
	node->prev = _list->head_node;
	node->next = _list->head_node->next;

	node->prev->next = node;
	node->next->prev = node;

	return ;
}

int list_is_empty(struct list * _list)
{
	if (_list->head_node->next == _list->head_node)
		return 1;
	else
		return 0;
}

void list_tail_del(struct list * _list)
{
	if (list_is_empty(_list))
		return ;

	struct node * head = _list->head_node;

	struct node * node = head->prev;

	node->prev->next = node->next;
	node->next->prev = node->prev;

	node->prev = node;
	node->next = node;

	free(node);
}

void list_head_del(struct list * _list)
{
	if (list_is_empty(_list))	
		return ;
	
	struct node * node = _list->head_node->next;

	node->prev->next = node->next;
	node->next->prev = node->prev;

	node->prev = node;
	node->next = node;

	free(node);
}

void list_del_by_data(struct list * _list, int _data)
{
	if (list_isempty(_list))
		return ;
	
	struct node * cur = _list->head_node->next;
	for (; cur != _list->head_node; cur = cur->next)
	{
		if (cur->data == _data)
	 	{
			cur->next->prev = cur->prev;
			cur->prev->next = cur->next;
			cur->next = cur;
			cur->prev = cur;

			free(cur);
			return ;
		}
	}
}

void list_del_by_pos(struct list * _list, int _pos)
{
	struct node * cur = _list->head_node->next;
	for (; _pos != 0 && cur != _list->head_node; _pos--)
		;
	
	if (_pos == 0) {
		cur->next->prev = cur->prev;
		cur->prev->next = cur->next;
		cur->next = cur;
		cur->prev = cur;

		free(cur);
		return ;
	}	
	else
		return ;
}

int list_size(struct list * _list)
{
	struct node * cur = _list->head_node->next;

	int i = 0;

	for (i = 0; cur != _list->head_node; cur = cur->next, i++)
		;

	return i;
}

void list_for_each(struct list * _list) 
{
	struct node* cur = _list->head_node->next;
	for (; cur != _list->head_node; cur = cur->next)
		printf("%d ", cur->data);

	printf("\n");

	return ;
}


