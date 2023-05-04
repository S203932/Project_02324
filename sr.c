#include <stdlib.h>
#include "linkedlist2.h"
typedef struct Node{
    char value;
    char suit;
    struct Node *next;
}Node;

char* SR(struct Node **head) {
    //Initializing data
    char *message = "Error happened during the shuffling";
    struct Node *Last = *head;
    struct Node *pile1 = NULL;
    int counter = 0;
    char data[2];

    //Moving all cards to a new pile
    while(counter < 52){
        data[0] = Last->value;
        data[1] = Last->suit;
        append(&pile1,data[0],data[1]);
        Last = Last -> next;
        counter++;
    }

    //Clearing original pile and adding the first card
    struct Node *pointer1 = pile1;
    data[0] = pointer1->value;
    data[1] = pointer1->suit;
    clearNewValue(head,data[0],data[1]);
    pointer1 = pointer1->next;

    counter = 0;
    int randomnumber;
    //Inserting the rest of the cards
    while(counter < 51){
        data[0] = pointer1->value;
        data[1] = pointer1->suit;
        randomnumber = rand() % (counter+2);
        if(randomnumber == 0){
            push(head, data[0],data[1]);
        } else{
            insertAt(head,randomnumber,data[0],data[1]);
        }
        pointer1 = pointer1->next;;
        counter++;
    }
    message = "OK";
    return message;
}