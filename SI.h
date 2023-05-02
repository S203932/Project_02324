#ifndef SI_H
#define SI_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void shuffle(Node* head);
void splitList(Node* head, Node** pile1_head_ref, Node** pile2_head_ref);
char* SI(int split, struct Node **head);

#endif /* SI_H */
