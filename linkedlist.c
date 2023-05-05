#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    char value;
    char suit;
    struct Node *next;
}Node;


/*Given a reference (pointer to pointer) to the head of a list
and a Char,  inserts a new node without reference*/
void clearNewValue(struct Node** head_ref, char value, char suit){
    // allocate node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    //put in the data
    new_node->value = value;
    new_node->suit = suit;
    new_node->next = NULL;

    //Make next of new node as head
    (*head_ref) = new_node;
}

/*Given a reference (pointer to pointer) to the head of a list
and Char,  inserts a new node without reference*/
void push (struct Node** head_ref, char value, char suit){

    // allocate node
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));

    //put in the data
    new_node->value = value;
    new_node->suit = suit;

    //Make next of new node as head
    new_node->next = (*head_ref);

    //move the head to point to the new node
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

/* Given a reference (pointer to pointer) to the head
   of a list a Char, appends a new node at the end */
void append(struct Node** head_ref, char value, char suit){

    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    struct Node *last = *head_ref;

    //allocate node
    new_node->value = value;
    new_node->suit = suit;
    new_node->next = NULL;

    //If the Linked List is empty, then make the new node as head
    if(*head_ref == NULL){
        *head_ref = new_node;
        return;
    }
    //Else traverse till the last node
    while(last->next != NULL){
        last = last->next;
    }

    //Change the next of last node
    last->next = new_node;
    return;
}

/* Function to reverse the linked list */
void reverse(struct Node** head_ref){
    struct Node* prev = NULL;
    struct Node* current  = *head_ref;
    struct Node* next = NULL;
    //struct Node *last = *head_ref;
    while(current != NULL){
        // Store next
        next = current->next;
        // Move pointers one position ahead.
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}
