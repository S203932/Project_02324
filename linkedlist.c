#include "linkedlist.h"



// Creating an empty linked list and return a pointer to the list//

Linked_list *CreateLinkedList() {
    Linked_list *newLinkedList;
    newLinkedList = (Linked_list *) malloc(sizeof(Linked_list));


    newLinkedList->size = 0;
    newLinkedList->head = NULL;
    newLinkedList->tail = NULL;

    return newLinkedList;
}

void Append_of_Card(Linked_list *list, struct CardList cards){
    struct CardList *newCard = (struct CardList *) malloc(sizeof(struct CardList));

    newCard->suit = cards.suit;
    newCard->value = cards.value;
    newCard->InGame = cards.InGame;
    newCard->faceDown = cards.faceDown;

    if( list -> size == 0) {

    }
}