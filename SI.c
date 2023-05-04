#include <stdlib.h>
#include "linkedlist2.h"
typedef struct Node{
    char value;
    char suit;
    struct Node *next;
}Node;

char* SI(int split, struct Node **head) {
    char* message = "";
    struct Node *pile1 = NULL, *pile2 = NULL;
    int counter = 0;
    struct Node *Last = *head;
    char data[2];
    char data2[2];


    // Check if split parameter is valid
    if (split < 1 || split >= 51) {
        return "Error: Split parameter is invalid";
    }


    // Split the deck into two piles
    while (counter < 52) {
        if(counter < split) {
            data[0] = Last->value;
            data[1] = Last->suit;
            append(&pile1,data[0],data[1]);
        }else{
            data2[0] = Last->value;
            data2[1] = Last->suit;
            append(&pile2,data2[0],data2[1]);
        }
        Last = Last -> next;
        counter++;
    }

    // Mix the two piles back into head
    // First add a card from each pile
    struct Node *pointer1 = pile1;
    data[0] = pointer1->value;
    data[1] = pointer1->suit;
    clearNewValue(head,data[0],data[1]);
    pointer1 = pointer1->next;

    struct Node *pointer2 = pile2;
    data2[0] = pointer2->value;
    data2[1] = pointer2->suit;
    append(head,data2[0],data2[1]);
    pointer2 = pointer2->next;


    counter = 0;

    //Intermix the two piles as long as there is cards in both
    while(counter< 50 && pointer1 != NULL && pointer2 != NULL){
        if(counter%2 == 0){
            data[0] = pointer1->value;
            data[1] = pointer1->suit;
            append(head,data[0],data[1]);
            pointer1 = pointer1->next;
        } else{
            data2[0] = pointer2->value;
            data2[1] = pointer2->suit;
            append(head,data2[0],data2[1]);
            pointer2 = pointer2->next;
        }
        counter++;
    }
    reverse(head);
    //Add leftover from pile 1
    if(pointer1 != NULL){
        while(pointer1 != NULL){
            data[0] = pointer1->value;
            data[1] = pointer1->suit;
            append(head,data[0],data[1]);
            pointer1 = pointer1->next;
        }
        //Add leftover from pile 2
    }else{
        while(pointer2 != NULL){
            data2[0] = pointer2->value;
            data2[1] = pointer2->suit;
            append(head,data2[0],data2[1]);
            pointer2 = pointer2->next;
        }
    }

    message = "OK";

    return message;
}
