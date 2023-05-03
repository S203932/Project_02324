#include "linkedlist.h"




// Creating an empty linked list
Linked_list *CreateLinkedList() {
    Linked_list *newLinkedList;
    newLinkedList = (Linked_list *) malloc(sizeof(Linked_list));

    newLinkedList->head = NULL;
    newLinkedList->tail = NULL;
    newLinkedList->size = 0;

    return newLinkedList;
}

// Add a new node to the beginning of existing list
void PrependCard(Linked_list *list, struct CardList card) {

    //allocating memory for node
    struct CardList * new_card =( struct CardList*) malloc(sizeof (struct CardList));

    //assigning new card to each node
    new_card->value = card.value;
    new_card->suit = card.suit;

    // Make new_card as head/
    if( list ->size == 0){
        new_card->next = NULL;
        new_card->prev = NULL;
        list->head =new_card;
        list->tail =new_card;
    } else {
        new_card->next = list ->head;
        list->head-> prev = new_card;
        new_card->prev = NULL;
        list->head = new_card;
    }

    list->size++;

    /*new_card->next = (*head_ref);

    // Head points to the new card//
    (*head_ref) = new_card;*/

}

void InsertAfter(Linked_list *list, struct CardList* prev_node, struct CardList card) {

    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }

    struct CardList * new_card =( struct CardList*) malloc(sizeof (struct CardList));

    //allocating memory for node
    new_card->value = card.value;
    new_card->suit = card.suit;

    //Make next of new card as next of prev_node
    new_card->next = prev_node->next;

    //move the next of prev_node as new_card
    prev_node->next = new_card;
}


// Add a new node to the end of existing list
void AppendCard(Linked_list *list, struct CardList card){
    //allocating memory for node
    struct CardList* new_card = (struct CardList*) malloc(sizeof(struct CardList ));

    /*struct card * tail = *head_ref;*/

    //assigning new card to each node
    new_card-> value  = card.value;
    new_card->suit = card.suit;

    // This new node is going to be the last node, so next is NULL
    if(list->size == 0) {
        new_card->next = NULL;
        new_card->prev = NULL;
        list->head = new_card;
        list->tail = new_card;
    } else {
        new_card->prev = list->tail;
        list->tail->next = new_card;
        new_card->next = NULL;
        list->tail = new_card;
    }

    list->size++;

    /*
    //If the Linked List is empty, then make the new node as head
    if (*head_ref == NULL)
    {
        *head_ref = new_card;
        return;
    }

    // traverse till the last node
    while (tail->next != NULL)
        tail = tail->next;

    // Change the next of last node
    tail->next = new_card;
    return;

    */
}





