#include <stdio.h>
#include <stdlib.h>
#include "card.h"

#define DEFAULT_FILENAME "cards.txt"
typedef struct Node{
    char value;
    char suit;
    struct Node *next;
}Node;

char* SD(char* filename, struct Node** head_ref) {
    char value;
    char suit;
    struct Node *last = *head_ref;

    if (filename == NULL) {
        filename = DEFAULT_FILENAME;
    }

    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        return "Something went wrong";
    }

    while (last->next != NULL) {
        char value = last->value;
        char suit = last->suit;
        fprintf(fp, "%c%c\n", value, suit);
        last = last->next;
    }

    fclose(fp);
    printf("Cards saved to file %s\n", filename);

return "ok";
}