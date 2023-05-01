#include <stdlib.h>
#include <stdio.h>
#include "ld.h"
#include "linkedlist.h"
#include "Card.h"

char* LD(char *filename ){
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

    char card;

    do {
        card = fgetc(file);
        //printf("%c", card);

    } while (card != EOF);
    fclose(file);
    return message;
}

