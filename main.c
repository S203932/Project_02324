#include <stdio.h>
#include <string.h>
#include <dirent.h>
#include "boardlist.h"
#include "ld.h"
#include "process_input.h"
#include "linkedlist.h"
#include "linkedlist2.h"
#include "SD.h"
#include "SI.h"
#include "sr.h"

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
    char p[] = "P";
    char q[] = "Q\0";
    char approved[] = "OK";
    char function[3];
    function[0] = '\0';
    function[1] = '\0';
    function[2] = '\0';
    struct Node* head_copy_p = NULL;
    struct Node* temp = NULL;
    struct Node* head = NULL;
    struct LinkedList* head_l = NULL;


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
            char *filePath = (char *) &path;
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
            char *filePath = (char *) &path;
            message = LD(filePath, &head);
            // QQ function
        }else if(strcmp(qq, function) == 0) {
            initialize = 0;
            quit = 1;
            // SW Function
        }else if(strcmp(sw, function) == 0) {
            message = show_board(head);
            // SI Function
        } else if(strcmp(si, function) == 0){
            //Reading input into path char array
            char path[strlen(input) - 2];
            for (int i = 3; i < strlen(input); i++) {
                path[i - 3] = input[i];
                if (i == strlen(input) - 1) {
                    path[i - 2] = '\0';
                }
            }
            //Determining the size of the input
            int size = sizeof(path) / sizeof(path[0]);
            //Value is too big
            if(size>3){
                message = "Split value invalid";
                //Value is none
            }else if(size<=1){
                int randomnumber;
                randomnumber = (rand() % 51)+1;
                message = SI(randomnumber,&head);
                //Otherwise within parameters
            }else{
                int number = 0;
                // If it is a 2-digit number
                if(size>2){
                    //Check if both values are numbers and not other characters
                    if(path[0] >= '0' && path[0] <= '9' && path[1] >= '0' && path[1] <= '9'){
                        number+= (path[0]-48)*10;
                        number+=path[1]-48;
                        message = SI(number, &head);
                    }else{
                        message = "Input was not only numbers";
                    }
                    // If it is a 1-digit number
                }else{
                    //Check if the values is a number and not a character
                    if(path[0] >= '0' && path[0] <= '9'){
                        number = path[0]-48;
                        message = SI(number, &head);
                    }else{
                        message = "Input was not only numbers";
                    }
                }
            }
            // SD Function
        } else if(strcmp(sd, function) == 0) {
            char path[strlen(input) - 2];
            for (int i = 3; i < strlen(input); i++) {
                path[i - 3] = input[i];
                if (i == strlen(input) - 1) {
                    path[i - 2] = '\0';
                }
            }
            char *filePath = (char *) &path;
            message = SD(filePath, &head);
            //SR Function
        }else if(strcmp(sr,function) == 0){
            message=SR(&head);
        }
        else if(strcmp(p, function) == 0) {

            // Making a copy of the list and using it during the play phase
            temp = head;
            append(&head_copy_p,temp->value,temp->suit);
            while(temp->next != NULL){
                temp = temp->next;
                append(&head_copy_p,temp->value,temp->suit);
            }

            //Using the new copy to initialize columns
            clearNewValueL(&head_l,*head_copy_p);
            initializePlayList(&head_l);
            message = "OK";

            moveFromCToC(&head_l, 1,7);
            moveFromCToC(&head_l,3,1);
            moveFromCToC(&head_l,2,5);
            while (initialize && !quit) {
                initial_play_board(head);
                printListL(head_l);
                // Getting user input
                strcpy(tempInput, process_input(message, input));
                strcpy(input, tempInput);
                memcpy(function, input, 2);
                function[0] = input[0];
                function[1] = input[1];

                //display error message on commands during play phase
                if ((strcmp(ld, function)) == 0 || (strcmp(sw, function)) == 0
                    || (strcmp(qq, function)) == 0 || (strcmp(si, function)) == 0 || (strcmp(sr, "LD")) == 0
                    || (strcmp(sd, function)) == 0 || (strcmp(p, function)) == 0) {
                    message = "this is not available in the play phase";
                }
                // quit the game and reset game variables.
                else if (strcmp(q, function) == 0) {
                    message = " Quitting the game..";
                    clearNewValueL(&head_l,*head_copy_p);
                    break;
                }

                else {
                    message = "Unknown command";
                }
            }
        }

    }
    return 0;
}



