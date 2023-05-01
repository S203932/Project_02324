#include <stdio.h>
#include <stdlib.h>

struct Node{
    char value;
    char suit;
    struct Node *next;
};

void push (struct Node** head_ref, char value, char suit){

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->value = value;

    new_node->suit = suit;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;

}

void insertAfter(struct Node* prev_node, char value, char suit){

    if(prev_node == NULL){
        printf("\nYou are using the linked list wrong as the previous node is NULL\n");
        return;
    }

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->value = value;

    new_node->suit = suit;

    new_node->next = new_node;

}

void append(struct Node** head_ref, char value, char suit){

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    struct Node *last = *head_ref;

    new_node->value = value;

    new_node->suit = suit;

    new_node->next = NULL;

    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }

    while(last->next != NULL){
        last = last->next;
    }

    last->next = new_node;

    return;
}

void printList(struct Node *node){
    while(node != NULL){
        printf("%c%c\n",node->value,node->suit);
        node = node->next;
    }
}