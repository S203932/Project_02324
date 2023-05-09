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

}