#include <stdio.h>
#include <stdlib.h>


typedef struct card {
    char value;
    char suit;
    struct card* next;
} Card;

typedef struct pile {
    Card* top;
    char name[3];
} Pile;

void print_card(Card* card) {
    if (card == NULL) {
        printf("   ");
        return;
    }
    printf("%c%c ", card->value, card->suit);
}

void print_pile(Pile* pile) {
    printf("%s:", pile->name);
    print_card(pile->top);
    printf("\n");
}

int main() {
    Pile tableau[7];
    Pile foundation[4];
    char suits[] = {'C', 'D', 'H', 'S'};
    char values[] = {'A', '2', '3', '4', '5', '6', '7', '8', '9', 'T', 'J', 'Q', 'K'};

    // Initialize tableau piles
    for (int i = 0; i < 7; i++) {
        Card* last_card = NULL;
        for (int j = i; j < 7; j++) {

            char suit = suits[rand() % 4];
            char value = values[rand() % 13];
            Card* card = (Card*)malloc(sizeof(Card));
            card->value = value;
            card->suit = suit;
            card->next = last_card;
            last_card = card;
        }
        tableau[i].top = last_card;
        sprintf(tableau[i].name, "C%d", i+1);
    }

    // Initialize foundation piles
    for (int i = 0; i < 4; i++) {
        foundation[i].top = NULL;
        sprintf(foundation[i].name, "F%d", i+1);
    }

    // Start screen
   // start_screen();

    // Print board
   // print_board(tableau, foundation);

}
