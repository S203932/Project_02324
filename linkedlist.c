#include "linkedlist.h"
#include "Card.h"

// Creating an empty linked list and return a pointer to the list//
void CreateLinkList() {
    struct card *head,*middle,*last;


    //allocating memory for each node
    head   = malloc(sizeof(struct card));
    middle = malloc(sizeof(struct card));
    last   = malloc(sizeof(struct card));

    //assigning suit to each node
    head->suit = head->suit;
    middle->suit = middle->suit;
    last->suit  = last->suit;

    //assigning value to each node
    head->value  = head->value;
    middle->value = middle->value;
    last->value  = last->value;

    //connecting each nodes. head->middle->last
    head->next   = middle;
    middle->next = last;
    last->next   = NULL;

    struct card *temp = head;

    while(temp != NULL)
    {
        printf("%d->",temp->value);
        temp = temp->next;
    }
    printf("NULL");


    return CreateLinkList();
}


