#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist2.h"

typedef struct Node{
    char value;
    char suit;
    struct Node *next;
}Node;

void empty_board(void){
    char *fs[] = {"F1", "F2", "F3", "F4"};
    printf("\nC1\tC2\tC3\tC4\tC5\tC6\tC7\n\n");
    int counter = 0;
    for(int i = 0; i < 7;i++){
        for(int j = 0; j < 7; j++){
            printf("[]\t");
        }
        if((i)%2 == 0){
            printf("\t[]\t%s\n",fs[counter]);
            counter++;
        }else{
            printf("\n");
        }
    }
    for(int i = 0; i < 3; i++){
        printf("[]\t");
    }
    printf("\n");
}


void start_board(void) {
    char *fs[] = {"F1", "F2", "F3", "F4"};
    printf("\nC1\tC2\tC3\tC4\tC5\tC6\tC7\n\n");
    int counter = 0;
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 7; j++) {
            printf("\t");
        }
        if((i)%2 == 0){
            printf("\t[]\t%s",fs[counter]);
            if(i != 6){
                printf("\n");
            }
            counter++;
        }else{
            printf("\n");
        }
    }
}

char* show_board(struct Node *node){
    char *message = "Something went wrong in showing the cards";
    char *fs[] = {"F1", "F2", "F3", "F4"};
    printf("\nC1\tC2\tC3\tC4\tC5\tC6\tC7\n\n");
    int counter = 0;
    for(int i = 0; i < 7;i++){
        for(int j = 0; j < 7; j++){

            printf("%c%c\t",node->value,node->suit);
            node = node->next;
        }
        if((i)%2 == 0){
            printf("\t[]\t%s\n",fs[counter]);
            counter++;
        }else{
            printf("\n");
        }
    }
    for(int i = 0; i < 3; i++){
        printf("%c%c\t",node->value,node->suit);
        node = node->next;
    }
    printf("\n");
    message = "OK";
    return message;
}

