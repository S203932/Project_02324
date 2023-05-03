#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

struct CardList{
    char suit;
    char value;
    struct CardList*next;
    struct CardList*prev;
};

typedef struct {
    struct CardList *head;
    struct CardList *tail;
    int size;
} Linked_list;

Linked_list *CreateLinkedList();

void PrependCard(Linked_list *list, struct CardList);

void InsertCard(Linked_list *list, struct CardList* prev_node, struct CardList);

void AppendCard(Linked_list *list, struct CardList);

