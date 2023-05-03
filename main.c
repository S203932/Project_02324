#include <stdio.h>
#include <string.h>
#include <dirent.h>

#include "boardlist.h"
#include "ld.h"
#include "process_input.h"
#include "linkedlist2.h"
//#include "Card.h"
#include "SD.h"
#include "SI.h"
typedef struct node node;

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
    char sw[] = "SW";
    char qq[] = "QQ";
    char si[] = "SI";
    char sr[] = "SR";
    char sd[] = "SD";
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

    // Resetting the initialize for next while loop
    initialize = 1;
    while(initialize && !quit){
        if(strcmp(sw, function) != 0){
            empty_board();
        }
        strcpy(tempInput, process_input(message, input));
        strcpy(input, tempInput);
        memcpy(function, input, 2);
        function[0] = input[0];
        function[1] = input[1];
        // The if statements is for the various functions available
        // LD function
        if (strcmp(ld, function) == 0) {
            head = NULL;
            char path[strlen(input) - 2];
            for (int i = 3; i < strlen(input); i++) {
                path[i - 3] = input[i];
                if (i == strlen(input) - 1) {
                    path[i - 2] = '\0';
                }
            }
            char *filePath = &path;
            message = LD(filePath, &head);
        // QQ function
        }else if(strcmp(qq, function) == 0) {
            initialize = 0;
            quit = 1;
        // SW Function
        }else if(strcmp(sw, function) == 0) {
            message = show_board(head);
            // SI Function
        } else if (strcmp(si, function) == 0){

            message = SI(4, &head);
        } else if (strcmp(sd, function) == 0){
            char path[strlen(input) - 2];
            for (int i = 3; i < strlen(input); i++) {
                path[i - 3] = input[i];
                if (i == strlen(input) - 1) {
                    path[i - 2] = '\0';
                }
            }
            char *filePath = &path;
            message = SD(filePath, &head);
        } else {    message = "Not a valid command, only LD or QQ is valid.";
        }
    }
    /*
    while()
    while(1) {
        empty_board();
        char *m2 = LD(" ");
        char input2[10];
        strcpy(input2, process_input(m2));
        printf("%s", input2);
    }
    */
    return 0;
}