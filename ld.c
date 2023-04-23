#include <stdlib.h>
#include <stdio.h>
#include "ld.h"


const char* LD(char *filename ){
    chdir("..");
    FILE* file;
    file = fopen(filename,"r" );
    char *message;
    if (NULL == file){
        char *backup = "cards.txt";
        file = fopen(backup,"r" );
        if (NULL == file){
            message="Error in opening the given file and backup file";
        }else{
            message = "OK";
        }
    }else{
        message = "OK";
    }

    char card;

    do {
        card = fgetc(file);
        printf("%c", card);

    } while (card != EOF);
    fclose(file);
    return message;
}

