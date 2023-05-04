#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    char value;
    char suit;
    struct Node *next;
}Node;

void clearNewValue(struct Node** head_ref, char value, char suit){
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->value = value;

    new_node->suit = suit;

    new_node->next = NULL;

    (*head_ref) = new_node;
}



void push (struct Node** head_ref, char value, char suit){

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->value = value;

    new_node->suit = suit;

    new_node->next = (*head_ref);

    (*head_ref) = new_node;

}


void insertAt(struct Node** head_ref, int position, char value, char suit){

    struct Node *last = *head_ref;

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    new_node->value = value;

    new_node->suit = suit;

    int counter = 0;

    while(counter < (position-1)){
        last = last->next;
        counter++;
    }

    new_node->next = last->next;
    last->next = new_node;

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

Node element(void){

}


void reverse(struct Node** headref){
    struct Node* prev = NULL;
    struct Node* current  = *headref;
    struct Node* next = NULL;
    struct Node *last = *headref;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *headref = prev;
}
