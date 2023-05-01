#include <stdio.h>
#include <string.h>

char* process_input(char* message, char function[50]) {
    char* input = malloc(sizeof(char) * 50);
    printf("\nLAST Command: %s\n", function);
    printf("Message: %s \n",message);
    printf("INPUT > ");
    fgets(input, 50, stdin);
    input[strcspn(input, "\n")] = '\0'; // remove trailing newline

    return input;


    /*while (1) {


        if (strcmp(input, "QQ") == 0) {
            printf("Exiting without saving!\n");
            break;
        }
        else if (strcmp(input, "Q") == 0) {
            printf("Saving and exiting...\n");
            // Save the game here
            break;
        }

        // Process the input command here
        printf("ok\n");

        strcpy(last_cmd, input);
    }*/
}