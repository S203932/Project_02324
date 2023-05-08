#include <stdio.h>
#include <stdlib.h>


struct Node;

void clearNewValue(struct Node** head_ref, char value, char suit);

void push (struct Node** head_ref, char value, char suit);

void append(struct Node** head_ref, char value, char suit);

void reverse(struct Node** head_ref);

void insertAt(struct Node** head_ref, int position, char value, char suit);

void printList (struct Node* node);

struct Node cutOfAtPosition(struct Node** head_ref, int position);

