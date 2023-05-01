#include <stdio.h>
#include <string.h>
#include "boardlist.h"
#include "ld.h"
#include "process_input.h"
#include <dirent.h>
#include "linkedlist.h"
#include "linkedlist2.h"
//#include "Card.h"
#include<unistd.h>

int main() {
    // Need to change the working directory, but only once
    chdir("..");


    //Initializing variables used later
    int initialize = 1;
    int quit = 0;
    char *message = "";
    char input[50] = ""; // Defines the maximum length available,
    char tempInput[50] = ""; // changes made here needs to also be changed else where
    char ld[] = "LD";
    char qq[] = "QQ";
    char approved[] = "OK";
    char function[3];
    function[0] = '\0';
    function[1] = '\0';
    function[2] = '\0';
    struct Node* head = NULL;


    //Loop that runs until cards is loaded successfully from txt via LD function
    while(initialize && !quit) {
        start_board();
        strcpy(tempInput, process_input(message, input));
        strcpy(input, tempInput);
        memcpy(function, input, 2);
        function[0] = input[0];
        function[1] = input[1];
        // The if statements is for the various functions available
        if (strcmp(ld, function) == 0) {
            char path[strlen(input) - 2];
            for (int i = 3; i < strlen(input); i++) {
                path[i - 3] = input[i];
                if (i == strlen(input) - 1) {
                    path[i - 2] = '\0';
                }
            }
            char *filePath = &path;
            message = LD(filePath, &head);
            if (strcmp(message, approved) == 0) {
                initialize = 0;
            }
        }else if(strcmp(qq, function) == 0){
            initialize = 0;
            quit = 1;
        }else{
            message = "Not a valid command, only LD or QQ is valid.";
        }
    }
    // Reseting the initialize for next while loop
    initialize = 1;
    while(initialize && !quit){
        empty_board();
        strcpy(tempInput, process_input(message, input));
        strcpy(input, tempInput);
        memcpy(function, input, 2);
        function[0] = input[0];
        function[1] = input[1];
        // The if statements is for the various functions available
        if (strcmp(ld, function) == 0) {
            char path[strlen(input) - 2];
            for (int i = 3; i < strlen(input); i++) {
                path[i - 3] = input[i];
                if (i == strlen(input) - 1) {
                    path[i - 2] = '\0';
                }
            }
            char *filePath = &path;
            message = LD(filePath, &head);
        }else if(strcmp(qq, function) == 0){
            initialize = 0;
            quit = 1;
        }else{
            message = "Not a valid command, only LD or QQ is valid.";
        }
    }
    /*
    while()
    empty_board();
    char *m2 = LD(" ");
    char input2[10];
    strcpy(input2, process_input(m2));
    printf("%s", input2);
    */
    return 0;
}