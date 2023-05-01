#include <stdio.h>

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