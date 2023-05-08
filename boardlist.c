#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"
#include "linkedlist2.h"

typedef struct Node{
    char value;
    char suit;
    struct Node *next;
}Node;

typedef struct LinkedList{
    struct Node node;
    struct LinkedList *next;
}LinkedList;

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

void initial_play_board(struct Node *node){
    char *fs[] = {"F1", "F2", "F3", "F4"};
    printf("\nC1\tC2\tC3\tC4\tC5\tC6\tC7\n\n");
    int counter = 0;
    for(int i = 0; i < 11;i++){
        for(int j = 0; j < 7; j++){

            if(i == 0 && j == 0){
                printf("%c%c\t",node->value,node->suit);
                node = node->next;
            } else if (j == 0){
                printf("\t");
            } else if (j <= i && i < 6){
                printf("%c%c\t",node->value,node->suit);
                node = node->next;
            } else if (i < 6 && j > i){
                printf("[]\t");
                node = node->next;
            } else if (i > 5 && ((i - j) >= 5)){
                printf("\t");
            } else if (i > 5 && ((i - j) <= 5)){
                printf("%c%c\t",node->value,node->suit);
                node = node->next;
            }
        }

        if((i)%2 == 0 && i < 7){
            printf("\t[]\t%s\n",fs[counter]);
            counter++;
        }else{
            printf("\n");
        }
    }
}

void play_board(struct LinkedList *linkedlist){

    struct LinkedList* columns = linkedlist;
    struct Node* node1 = &columns->node;
    columns = columns->next;
    struct Node* node2 = &columns->node;
    columns = columns->next;
    struct Node* node3 = &columns->node;
    columns = columns->next;
    struct Node* node4 = &columns->node;
    columns = columns->next;
    struct Node* node5 = &columns->node;
    columns = columns->next;
    struct Node* node6 = &columns->node;
    columns = columns->next;
    struct Node* node7 = &columns->node;

    columns = columns->next;
    struct Node* node8 = &columns->node;
    while(node8->next != NULL){
        node8 = node8->next;
    }
    columns = columns->next;
    struct Node* node9 = &columns->node;
    while (node9->next != NULL){
        node9 = node9->next;
    }
    columns = columns->next;
    struct Node* node10 = &columns->node;
    while(node10->next != NULL){
        node10 = node10->next;
    }
    columns = columns->next;
    struct Node* node11 = &columns->node;
    while(node11->next != NULL){
        node11 = node11->next;
    }


    char *fs[] = {"F1", "F2", "F3", "F4"};
    printf("\nC1\tC2\tC3\tC4\tC5\tC6\tC7\n\n");
    int counter = 0;
    for(int i = 0; i < 11;i++){
        for(int j = 0; j < 7; j++){
            if(j == 0){
                if(node1 != NULL && node1->value != '\0' && node1->suit != '\0'){
                    printf("%c%c\t",node1->value,node1->suit);
                    node1 = node1->next;
                }else{
                    printf("\t");
                    if(node1 != NULL){
                        node1 = node1->next;
                    }
                }
            }else if(j == 1){
                if(i < 1 && node2->next != NULL){
                    printf("[]\t");
                    node2 = node2->next;
                }else{
                    if(node2 != NULL && node2->value != '\0' && node2->suit != '\0'){
                        printf("%c%c\t",node2->value,node2->suit);
                        node2 = node2->next;
                    }else{
                        printf("\t");
                        if(node2 != NULL){
                            node2 = node2->next;
                        }
                    }
                }


            }else if(j == 2){
                if(i < 2 && node3->next != NULL){
                    printf("[]\t");
                    node3 = node3->next;
                }else{
                    if(node3 != NULL && node3->value != '\0' && node3->suit != '\0'){
                        printf("%c%c\t",node3->value,node3->suit);
                        node3 = node3->next;
                    }else{
                        printf("\t");
                        if(node3 != NULL){
                            node3 = node3->next;
                        }
                    }
                }
            }else if(j == 3){
                if(i < 3 && node4->next != NULL){
                    printf("[]\t");
                    node4 = node4->next;
                }else{
                    if(node4 != NULL && node4->value != '\0' && node4->suit != '\0'){
                        printf("%c%c\t",node4->value,node4->suit);
                        node4 = node4->next;
                    }else{
                        printf("\t");
                        if(node4 != NULL){
                            node4 = node4->next;
                        }
                    }
                }
            }else if(j == 4){
                if(i < 4 && node5->next != NULL){
                    printf("[]\t");
                    node5 = node5->next;
                }else{
                    if(node5 != NULL && node5->value != '\0' && node5->suit != '\0'){
                        printf("%c%c\t",node5->value,node5->suit);
                        node5 = node5->next;
                    }else{
                        printf("\t");
                        if(node5 != NULL){
                            node5 = node5->next;
                        }
                    }
                }
            }else if(j == 5){
                if(i < 5 && node6->next != NULL){
                    printf("[]\t");
                    node6 = node6->next;
                }else{
                    if(node6 != NULL && node6->value != '\0' && node6->suit != '\0'){
                        printf("%c%c\t",node6->value,node6->suit);
                        node6 = node6->next;
                    }else{
                        printf("\t");
                        if(node6 != NULL){
                            node6 = node6->next;
                        }
                    }
                }
            }else if(j == 6){
                if(i < 6 && node7->next != NULL){
                    printf("[]\t");
                    node7 = node7->next;
                }else{
                    if(node7 != NULL && node7->value != '\0' && node7->suit != '\0'){
                        printf("%c%c\t",node7->value,node7->suit);
                        node7 = node7->next;
                    }else{
                        printf("\t");
                        if(node7 != NULL){
                            node7 = node7->next;
                        }
                    }
                }

            }
        }

        if((i)%2 == 0 && i < 7){
            if(i == 0){
                if(node8->value != '\0' && node8->suit !='\0'){
                    printf("\t%c%c\t%s\n",node8->value,node8->suit,fs[counter]);
                    counter++;
                }else{
                    printf("\t[]\t%s\n",fs[counter]);
                    counter++;
                }
            }else if(i == 2){
                if(node9->value != '\0' && node9->suit !='\0'){
                    printf("\t%c%c\t%s\n",node9->value,node9->suit,fs[counter]);
                    counter++;
                }else{
                    printf("\t[]\t%s\n",fs[counter]);
                    counter++;
                }
            }else if(i == 4){
                if(node10->value != '\0' && node10->suit !='\0'){
                    printf("\t%c%c\t%s\n",node10->value,node10->suit,fs[counter]);
                    counter++;
                }else{
                    printf("\t[]\t%s\n",fs[counter]);
                    counter++;
                }
            }else if(i == 6){
                if(node11->value != '\0' && node11->suit !='\0'){
                    printf("\t%c%c\t%s\n",node11->value,node11->suit,fs[counter]);
                    counter++;
                }else{
                    printf("\t[]\t%s\n",fs[counter]);
                    counter++;
                }
            }
        }else{
            printf("\n");
        }
    }
    counter = 0;
    while(node1 != NULL || node2 != NULL || node3 != NULL || node4 != NULL || node5 != NULL || node6 != NULL || node7 != NULL){
        if(node1 != NULL){
            printf("%c%c\t",node1->value,node1->suit);
            node1 = node1->next;
        }else{
            printf("\t");
        }

        if(node2 != NULL){
            printf("%c%c\t",node2->value,node2->suit);
            node2 = node2->next;
        }else{
            printf("\t");
        }

        if(node3 != NULL){
            printf("%c%c\t",node3->value,node3->suit);
            node3 = node3->next;
        }else{
            printf("\t");
        }

        if(node4 != NULL){
            printf("%c%c\t",node4->value,node4->suit);
            node4 = node4->next;
        }else{
            printf("\t");
        }

        if(node5 != NULL){
            printf("%c%c\t",node5->value,node5->suit);
            node5 = node5->next;
        }else{
            printf("\t");
        }

        if(node6 != NULL){
            printf("%c%c\t",node6->value,node6->suit);
            node6 = node6->next;
        }else{
            printf("\t");
        }

        if(node7 != NULL){
            printf("%c%c\t\n",node7->value,node7->suit);
            node7 = node7->next;
        }else{
            printf("\t\n");
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

