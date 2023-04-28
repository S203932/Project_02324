#include "linkedlist.h"
#include "Card.h"


// Creating an empty linked list
Linked_list *CreateLinkedList() {
    Linked_list *newLinkedList;
    newLinkedList = (Linked_list *) malloc(sizeof(Linked_list));

    newLinkedList->head = NULL;
    newLinkedList->tail = NULL;
    newLinkedList->size = 0;

    return newLinkedList;
}

// Creating linked list and return a pointer to the list//
void PrependCard(Linked_list *list, struct card CardList) {

    //allocating memory for node
    struct card * new_card =( struct card*) malloc(sizeof (struct card));

    //assigning new card to each node
    new_card->value = CardList.value;
    new_card->suit = CardList.suit;

    // Make new_card as head/
    if( list ->size == 0){
        new_card->next = NULL;
        list->head =new_card;
        list->tail =new_card;
    } else {
        new_card->next = list ->head;
        list->head->prev= NULL;
        list->head = new_card;
    }

    list->size++;

    /*new_card->next = (*head_ref);

    // Head points to the new card//
    (*head_ref) = new_card;*/

}

void InsertCard(struct card* prev_node, struct card CardList) {

    if (prev_node == NULL)
    {
        printf("the given previous node cannot be NULL");
        return;
    }

    struct card * new_card =( struct card*) malloc(sizeof (struct card));

    //allocating memory for node
    new_card->value = CardList.value;
    new_card->suit = CardList.suit;

    //Make next of new card as next of prev_node
    new_card->next = prev_node->next;

    //move the next of prev_node as new_card
    prev_node->next = new_card;
}



void AppendCard(Linked_list *list, struct card CardList)
{
    //allocating memory for node
    struct card* new_card = (struct card*) malloc(sizeof(struct card));

    /*struct card * tail = *head_ref;*/

    //assigning new card to each node
    new_card-> value  = CardList.value;
    new_card->suit = CardList.suit;

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





