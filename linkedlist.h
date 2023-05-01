#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    struct card *head;
    struct card *tail;
    int size;
} Linked_list;

Linked_list *CreateLinkedList();

void PrependCard(Linked_list *list, struct card CardList);

void InsertCard(struct card* prev_node, struct card CardList);

void AppendCard(Linked_list *list, struct card CardList);

