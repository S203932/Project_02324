#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>


struct Node;

void push (struct Node** head_ref, char value, char suit);

void insertAfter(struct Node* prev_node, char value, char suit);

void append(struct Node** head_ref, char value, int suit);

void printList(struct Node *node);

