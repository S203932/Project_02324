#include <stdio.h>
#include <stdlib.h>


struct Node;

void clearNewValue(struct Node** head_ref, char value, char suit);

void push (struct Node** head_ref, char value, char suit);

void insertAfter(struct Node* prev_node, char value, char suit);

void append(struct Node** head_ref, char value, char suit);

void printList(struct Node *node);

void reverse(struct Node** headref);

void insertAt(struct Node** head_ref, int position, char value, char suit);

