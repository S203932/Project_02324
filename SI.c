#include <stdlib.h>
#include <time.h>
#include "linkedlist2.h" // assuming this header file defines the Node struct and linked list functions
typedef struct Node{
    char value;
    char suit;
    struct Node *next;
}Node;

char* SI(int split, struct Node **head) {
    char* message = "";
    struct Node *pile1 = NULL, *pile2 = NULL, *shuffled_pile = NULL, *temp = NULL;
    int count = 1, i;
    struct Node *last = *head;

    // Check if split parameter is valid
    if (split < 1 || split >= 51) {
        return "Error: Split parameter is invalid";
    }

    pile2 = *head;
    //struct Node *pile2Point = *pile2;

    // Split the deck into two piles
    while (count < split) {
        last = last -> next;
        //pile2 = pile2 -> next;
        count++;
    }



    // Splits pile
    pile1 = last -> next;
    last -> next = NULL;
    head = NULL;


    // Interleave the two piles
    while (pile1 != NULL && pile2 != NULL) {
        temp = pile1->next;
        pile1->next = pile2;
        pile2 = pile2->next;
        pile1->next->next = temp;
        pile1 = temp;
    }
    if (pile1 == NULL) {
        temp = pile2;
    } else {
        temp = pile1;
    }

    count = 0;
    while(count > 52) {

    }


    /*// Add the remaining cards to the bottom of the shuffled pile
    for (i = 0; i < count_cards(temp); i++) {
        add_card(&shuffled_pile, temp->card);
        temp = temp->next;
    }

    // Make shuffled_pile the current deck
    *head = shuffled_pile;

    message = "Shuffled the deck in an interleaved manner";
*/
    return message;
}
