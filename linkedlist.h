#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// start of structs//

struct CardList {
    bool faceDown;
    bool InGame;
    char suit;
    char value;
};

typedef struct {
    struct CardList* head;
    struct CardList* tail;
    int size;
} Linked_list;

// Start of methods//
Linked_list *createLinkedList();

void Append_of_Card(Linked_list *list, struct CardList cards);
void Prepend_of_Card (Linked_list *list, struct ListCard card);