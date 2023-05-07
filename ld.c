#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "linkedlist.h"
#include "Card.h"

char* LD(char *filename, struct Node **node){
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

    char card[2];
    int counter = 0;
    do {
        fgets(card,5,file);
        append(node,card[0],card[1]);
        counter++;
    } while (counter<52);
    fclose(file);
    return message;
}

