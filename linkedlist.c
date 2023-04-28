#include "linkedlist.h"
#include "Card.h"

Linked_list *MakeLinkedList() {
    Linked_list *newLinkedList;
    newLinkedList = (Linked_list *) malloc(sizeof(Linked_list));

    newLinkedList->size = 0;
    newLinkedList->head = NULL;
    newLinkedList->tail = NULL;

    return newLinkedList;
}

// Creating linked list and return a pointer to the list//
void PrependCard(Linked_list *list, struct card** head_ref, struct card CardList) {

    //allocating memory for node
    struct card * new_card =( struct card*) malloc(sizeof (struct card));

    //assigning new card to each node
    new_card->value = CardList.value;
    new_card->suit = CardList.suit;

    // Make new_card as head/
    new_card->next = (*head_ref);

    // Head points to the new card//
    (*head_ref) = new_card;

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



void AppendCard(struct Node** head_ref, struct card CardList)
{
    //allocating memory for node
    struct card* new_card = (struct card*) malloc(sizeof(struct card));

    struct card * tail = *head_ref;

    //assigning new card to each node
    new_card-> value  = CardList.value;
    new_card->suit = CardList.suit;

    // This new node is going to be the last node, so next is NULL
    new_card->next = NULL;

    //If the Linked List is empty, then make the new node as head */
    if (*head_ref == NULL)
    {
        *head_ref = new_card;
        return;
    }

    // traverse till the last node
    while (tail->next != NULL)
        tail = tail->next;

    // Change the next of last node */
    tail->next = new_card;
    return;
}





