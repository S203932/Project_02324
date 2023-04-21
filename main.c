#include <stdio.h>


int main() {


    char *fs[] = {"F1", "F2", "F3", "F4"};
    printf("\nC1\tC2\tC3\tC4\tC5\tC6\tC7\n");
    int counter = 0;
    for(int i = 0; i < 7;i++){
        for(int j = 0; j < 7; j++){
            printf("[]\t");
        }
        if((i)%2 == 0){
            printf("[]\t%s\n",fs[counter]);
            counter++;
        }else{
            printf("\n");
        }

    }
    for(int i = 0; i < 3; i++){
        printf("[]\t");
    }
    return 0;
}
