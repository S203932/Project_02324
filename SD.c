#include <stdio.h>
#include <stdlib.h>
#include "card.h"
#include <string.h>
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
    char check[] = " ";
    FILE* file;
    char *message;
    if(strcmp(filename,check) == 0){
        char *backup = "cards.txt";
        file = fopen(backup,"r" );
        if (NULL == file){
            message="Error in opening cards.txt\0";
        }else{
            message = "OK\0";
        }
    }else{
        file = fopen(filename,"r" );
        if (NULL == file){
            message="Error in opening the given file\0";
        }else{
            message = "OK\0";
        }
    }

    while (last != NULL) {
        char value = last->value;
        char suit = last->suit;
        fprintf(file, "%c%c\n", value, suit);
        last = last->next;
    }

    fclose(file);
    printf("Cards saved to file %s\n", filename);

return "ok";
}