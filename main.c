#include <stdio.h>
#include <string.h>


#include "boardlist.h"
#include "ld.h"
#include "process_input.h"
#include "linkedlist.h"
#include "linkedlist2.h"
#include "SD.h"
#include "SI.h"
#include "sr.h"



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
    char q[] = "Q";
    char approved[] = "OK";
    char function[3];
    function[0] = '\0';
    function[1] = '\0';
    function[2] = '\0';
    char move[10];
    int counter = 0;
    while(counter<10){
        move[counter] = '\0';
        counter++;
    }
    counter = 0;
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
            message = "Not a valid command, only LD or QQ is valid.\0";
        }
    }


    while(!quit){
        if(strcmp(sw, function) != 0){
            empty_board();
        }
        strcpy(tempInput, process_input(message, input));
        strcpy(input, tempInput);
        memcpy(function, input, 2);
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
                message = "Split value invalid\0";
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
                        message = "Input was not only numbers\0";
                    }
                    // If it is a 1-digit number
                }else{
                    //Check if the values is a number and not a character
                    if(path[0] >= '0' && path[0] <= '9'){
                        number = path[0]-48;
                        message = SI(number, &head);
                    }else{
                        message = "Input was not only numbers\0";
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
            clearNewValue(&head_copy_p,temp->value,temp->suit);
            while(temp->next != NULL){
                temp = temp->next;
                append(&head_copy_p,temp->value,temp->suit);
            }

            //Using the new copy to initialize columns
            clearNewValueL(&head_l,*head_copy_p);
            initializePlayList(&head_l);
            message = "OK\0";


            while (!quit) {;
                play_board(head_l);
                // Getting user input
                strcpy(tempInput, process_input(message, input));
                strcpy(input, tempInput);
                memcpy(function, input, 2);
                memcpy(move, input, 9);


                //display error message on commands during play phase
                if ((strcmp(ld, function)) == 0 || (strcmp(sw, function)) == 0
                    || (strcmp(qq, function)) == 0 || (strcmp(si, function)) == 0 || (strcmp(sr, "LD")) == 0
                    || (strcmp(sd, function)) == 0 || (strcmp(p, function)) == 0) {
                    message = "Command not available at this point\0";
                }else if(move[9] != '\0'){
                    message = "An error has occured when reading input";


                //They want to move from a column
                }else if(move[0] == 'C'){

                    //They want to move a specific card
                    if(move[2] == ':'){

                        //They want to move the card to a column
                        if(move[7] == 'C'){
                            //A check to see if the formality is there
                            if(move[5] =='-' && move[6] == '>'){
                                //Check if the column they move from is valid
                                if(move[1]>= '1' && move[1]<='7'){
                                    //Check if the column they move to is valid
                                    if(move[8]>= '1' && move[8] <='7'){
                                        //Check if it is a valid suit
                                        if(move[4] == 'H' || move[4] == 'C' || move[4] == 'D' || move[4] == 'S'){
                                            //Check if card is a valid value
                                            if(convertValue(move[3])>=1 && convertValue(move[3])<=13){
                                                //Function to move the given card
                                                message = moveCardFromCToC(&head_l,move[1]-48,move[8]-48,move[3],move[4]);
                                            }else{
                                                message = "Card is not of valid value\0";
                                            }
                                        }else{
                                            message = "Card is not of valid suit\0";
                                        }
                                    }else{
                                        message = "Invalid column to move to\0";
                                    }
                                }else{
                                    message = "Invalid column to move from\0";
                                }
                            }else{
                                message = "Not valid format for move\0";
                            }

                        //They want to move the card to a foundation
                        }else if(move[7] == 'F'){
                            //A check to see if the formality is there
                            if(move[5] =='-' && move[6] == '>'){
                                //Check if the column they move from is valid
                                if(move[1]>= '1' && move[1]<='7'){
                                    //Check if the foundation they move to is valid
                                    if(move[8]>= '1' && move[8] <='4'){
                                        //Check if it is a valid suit
                                        if(move[4] == 'H' || move[4] == 'C' || move[4] == 'D' || move[4] == 'S'){
                                            //Check if card is a valid value
                                            if(convertValue(move[3])>=1 && convertValue(move[3])<=13){
                                                //Function to move the given card
                                                message = moveCardFromCToF(&head_l, move[1]-48,move[8]-48+7,move[3],move[4]);
                                            }else{
                                                message = "Card is not of valid value\0";
                                            }
                                        }else{
                                            message = "Card is not of valid suit\0";
                                        }
                                    }else{
                                        message = "Invalid foundation to move to\0";
                                    }
                                }else{
                                    message = "Invalid column to move from\0";
                                }
                            }else{
                                message = "Not valid format for move\0";
                            }
                        }else{
                            message = "Destination value invalid\0";
                        }

                    //They want to move any card
                    }else{
                        //Check if formality terminology to move is correct
                        if(move[6] == '\0'){
                            //Check formality
                            if(move[2] == '-' && move[3] == '>'){
                                //Check if they move to column
                                if(move[4] == 'C'){
                                    //Check if move from column is correct
                                    if(move[1] >= '1' && move[1] <= '7'){
                                        //Check if move to column is correct
                                        if(move[5] >= '1' && move[5] <='7'){
                                            message = moveFromCToC(&head_l,move[1]-48,move[5]-48);
                                        }else{
                                            message = "Invalid move to column\0";
                                        }
                                    }else{
                                        message = "Invalid move from column\0";
                                    }
                                //Check if they move to foundation
                                }else if(move[4] == 'F'){
                                    //Check if move from column is correct
                                    if(move[1] >= '1' && move[1] <= '7'){
                                        //Check if move to foundation is correct
                                        if(move[5] >= '1' && move[5] <='4'){
                                            char card[] = "\0\0";
                                            message = moveCardFromCToF(&head_l, move[1]-48,move[5]-48+7,card[0],card[1]);
                                        }else{
                                            message = "Invalid move to foundation\0";
                                        }
                                    }else{
                                        message = "Invalid move from column\0";
                                    }
                                }else{
                                    message = "Destination is not column or foundation and therefore invalid\0";
                                }
                            }else{
                                message = "Invalid terminology\0";
                            }
                        }else{
                            message = "Invalid terminology\0";
                        }
                    }

                //They move from a foundation
                }else if(move[0] == 'F'){
                    //They want to move a specific card
                    if(move[2] == ':'){
                        //They want to move the card to a column
                        if(move[7] == 'C'){
                            //A check to see if the formality is there
                            if(move[5] =='-' && move[6] == '>'){
                                //Check if the foundation they move from is valid
                                if(move[1]>= '1' && move[1]<='4'){
                                    //Check if the column they move to is valid
                                    if(move[8]>= '1' && move[8] <='7'){
                                        //Check if it is a valid suit
                                        if(move[4] == 'H' || move[4] == 'C' || move[4] == 'D' || move[4] == 'S'){
                                            //Check if card is a valid value
                                            if(convertValue(move[3])>=1 && convertValue(move[3])<=13){
                                                //Function to move the given card
                                                message = moveCardFromCToC(&head_l,move[1]-48+7,move[8]-48,move[3],move[4]);
                                            }else{
                                                message = "Card is not of valid value\0";
                                            }
                                        }else{
                                            message = "Card is not of valid suit\0";
                                        }
                                    }else{
                                        message = "Invalid column to move to\0";
                                    }
                                }else{
                                    message = "Invalid foundation to move from\0";
                                }
                            }else{
                                message = "Not valid format for move\0";
                            }
                        }else{
                            message = "Destination value invalid\0";
                        }


                        //They want to move any card
                    }else{
                        //Check if formality terminology to move is correct
                        if(move[6] == '\0'){
                            //Check formality
                            if(move[2] == '-' && move[3] == '>'){
                                //Check if they move to column
                                if(move[4] == 'C'){
                                    //Check if move from column is correct
                                    if(move[1] >= '1' && move[1] <= '4'){
                                        //Check if move to column is correct
                                        if(move[5] >= '1' && move[5] <='7'){
                                            message = moveFromCToC(&head_l,move[1]-48+7,move[5]-48);
                                        }else{
                                            message = "Invalid move to column\0";
                                        }
                                    }else{
                                        message = "Invalid move from column\0";
                                    }
                                    //Check if they move to foundation
                                }else{
                                    message = "Destination is not column and therefore invalid\0";
                                }
                            }else{
                                message = "Invalid terminology\0";
                            }
                        }else{
                            message = "Invalid terminology\0";
                        }
                    }
                }
                // quit the game and reset game variables.
                else if (strcmp(q, function) == 0) {
                    message = "OK\0";
                    quit = 1;
                }

                else {
                    message = "Unknown command\0";
                }

                if(gameWon(&head_l)){
                    message = "Game was won returned to main menu\0";
                    quit = 1;
                }
            }
            quit = 0;
        }else{
            message="Invalid command\0";
        }

    }
    return 0;
}



