#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"
typedef struct Node{
    char value;
    char suit;
    struct Node *next;
}Node;

typedef struct LinkedList{
    struct Node node;
    struct LinkedList *next;
}LinkedList;


int convertValue(char value){

    if(value == 'A'){
        return 1;
    }else if(value == 'T'){
        return 10;
    }else if(value == 'J'){
        return 11;
    }else if(value == 'Q'){
        return 12;
    }else if(value == 'K'){
        return 13;
    }else{
        return value-48;
    }
}


void pushL (struct LinkedList** head_ref_l, struct Node head_ref){

    // allocate linkedlist
    struct LinkedList* new_linkedlist = (struct LinkedList*) malloc(sizeof(struct LinkedList));

    //put in the data
    new_linkedlist->node = head_ref;


    new_linkedlist->next = (*head_ref_l);



    //move the head to point to the new node
    (*head_ref_l) = new_linkedlist;

}

void initializePlayList(struct LinkedList** head_ref_l){

    struct LinkedList *last = *head_ref_l;

    //Firstly creating all the columns and assigning them in order


    //First column

    struct LinkedList* new_linkedList1 = (struct LinkedList*) malloc(sizeof(struct LinkedList));

    new_linkedList1->node = cutOfAtPosition(head_ref_l,1);

    new_linkedList1->next = NULL;

    last->next = new_linkedList1;



    // Second column

    struct LinkedList* new_linkedList2 = (struct LinkedList*) malloc(sizeof(struct LinkedList));

    new_linkedList2->node = cutOfAtPosition(&new_linkedList1,1);

    new_linkedList2->next = NULL;

    new_linkedList1->next = new_linkedList2;


    //Third column

    struct LinkedList* new_linkedList3 = (struct LinkedList*) malloc(sizeof(struct LinkedList));

    new_linkedList3->node = cutOfAtPosition(&new_linkedList2,1);

    new_linkedList3->next = NULL;

    new_linkedList2->next = new_linkedList3;


    //Fourth column

    struct LinkedList* new_linkedList4 = (struct LinkedList*) malloc(sizeof(struct LinkedList));

    new_linkedList4->node = cutOfAtPosition(&new_linkedList3,1);

    new_linkedList4->next = NULL;

    new_linkedList3->next = new_linkedList4;


    //Fifth column

    struct LinkedList* new_linkedList5 = (struct LinkedList*) malloc(sizeof(struct LinkedList));

    new_linkedList5->node = cutOfAtPosition(&new_linkedList4,1);

    new_linkedList5->next = NULL;

    new_linkedList4->next = new_linkedList5;


    //Sixth column

    struct LinkedList* new_linkedList6 = (struct LinkedList*) malloc(sizeof(struct LinkedList));

    new_linkedList6->node = cutOfAtPosition(&new_linkedList5,1);

    new_linkedList6->next = NULL;

    new_linkedList5->next = new_linkedList6;


    //Seventh column
    struct LinkedList* new_linkedList7 = (struct LinkedList*) malloc(sizeof(struct LinkedList));

    //new_linkedList7->node = cutOfAtPosition(&new_linkedList6,1);

    struct Node node7;

    node7.value = '\0';

    node7.suit = '\0';

    node7.next = NULL;

    new_linkedList7->node = node7;

    new_linkedList7->next = NULL;

    new_linkedList6->next = new_linkedList7;


    //Eigth column

    struct LinkedList* new_linkedList8 = (struct LinkedList*) malloc(sizeof(struct LinkedList));

    new_linkedList8->next = NULL;

    struct Node node8;

    node8.value = '\0';

    node8.suit = '\0';

    node8.next = NULL;

    new_linkedList8->node = node8;

    new_linkedList7->next = new_linkedList8;


    //Ninenth column

    struct LinkedList* new_linkedList9 = (struct LinkedList*) malloc(sizeof(struct LinkedList));

    new_linkedList9->next = NULL;

    struct Node node9;

    node9.value = '\0';

    node9.suit = '\0';

    node9.next = NULL;

    new_linkedList9->node = node9;

    new_linkedList8->next = new_linkedList9;


    //Tenth column

    struct LinkedList* new_linkedList10 = (struct LinkedList*) malloc(sizeof(struct LinkedList));

    new_linkedList10->next = NULL;

    struct Node node10;

    node10.value = '\0';

    node10.suit = '\0';

    node10.next = NULL;

    new_linkedList10->node = node10;

    new_linkedList9->next = new_linkedList10;


    //Assigning the cards from row 2 to 6

    struct Node* temp;

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 6;j++){
            if(j == 0){
                temp = &new_linkedList6->node;
                temp = temp->next;
                new_linkedList1->node.next = temp;
                new_linkedList1 = new_linkedList1->node.next;
                new_linkedList6->node.next = NULL;
            }else if(j == 1){
                temp = &new_linkedList1->node;
                temp = temp->next;
                new_linkedList2->node.next = temp;
                new_linkedList2 = new_linkedList2->node.next;
                new_linkedList1->node.next = NULL;
            }else if(j == 2){
                temp = &new_linkedList2->node;
                temp = temp->next;
                new_linkedList3->node.next = temp;
                new_linkedList3 = new_linkedList3->node.next;
                new_linkedList2->node.next = NULL;
            }else if(j == 3){
                temp = &new_linkedList3->node;
                temp = temp->next;
                new_linkedList4->node.next = temp;
                new_linkedList4 = new_linkedList4->node.next;
                new_linkedList3->node.next = NULL;
            }else if(j == 4){
                temp = &new_linkedList4->node;
                temp = temp->next;
                new_linkedList5->node.next = temp;
                new_linkedList5 = new_linkedList5->node.next;
                new_linkedList4->node.next = NULL;
            }else if(j == 5){
                temp = &new_linkedList5->node;
                temp = temp->next;
                new_linkedList6->node.next = temp;
                new_linkedList6 = new_linkedList6->node.next;
                new_linkedList5->node.next = NULL;
            }
        }
    }

    temp = temp->next;

    //Assigning the cards from row 7 to 11

    for(int i = 0; i < 5; i++){
        for(int j = 0; j < 5; j++){
            if(j == 0 && (j-i) == 0){
                new_linkedList2->node.next = temp;
                new_linkedList2 = new_linkedList2->node.next;
                temp = temp->next;
                new_linkedList2->node.next = NULL;
            }else if(j == 1 && (j-i)>= 0){
                new_linkedList3->node.next = temp;
                new_linkedList3 = new_linkedList3->node.next;
                temp = temp->next;
                new_linkedList3->node.next = NULL;
            }else if(j == 2 && (j-i)>=0){
                new_linkedList4->node.next = temp;
                new_linkedList4 = new_linkedList4->node.next;
                temp = temp->next;
                new_linkedList4->node.next = NULL;
            }else if(j == 3 && (j-i)>=0){
                new_linkedList5->node.next = temp;
                new_linkedList5 = new_linkedList5->node.next;
                temp = temp->next;
                new_linkedList5->node.next = NULL;
            }else if(j == 4 && (j-i)>=0){
                new_linkedList6->node.next = temp;
                new_linkedList6 = new_linkedList6->node.next;
                temp = temp->next;
                new_linkedList6->node.next = NULL;
            }
        }
    }
}



void clearNewValueL(struct LinkedList** head_ref_l,struct Node head_ref){

    // allocate linkedlist
    struct LinkedList* new_linkedlist = (struct LinkedList*) malloc(sizeof(struct LinkedList));


    //put in the data
    new_linkedlist->node = head_ref;
    new_linkedlist->next = NULL;

    //move the head to point to the new node
    (*head_ref_l) = new_linkedlist;




}

char* moveFromCToC(struct LinkedList** head_ref_l,int from,int to){
    if(from > 8 || from < 1){
        return "Invalid origin value";
    }else if(to > 8 || to < 1){
        return "Invalid destination value";
    }else if (from == to){
        return "Cannot move card to same column";
    }

    char* message = "OK";
    struct LinkedList origin = **head_ref_l;
    struct LinkedList* origin_p = *head_ref_l;
    struct LinkedList destination = **head_ref_l;
    struct LinkedList* destination_p = *head_ref_l;
    struct Node* des_node_p;
    struct Node* ori_node_p;
    struct Node *node_temp = (struct Node*) malloc(sizeof(struct Node));;

    int counter = 0;
    int o_empty = 0;
    int d_empty = 0;
    while(counter<(from-1)){
        origin = *origin.next;
        origin_p = origin_p->next;
        counter++;
    }

    ori_node_p = &origin_p->node;

    if(origin.node.next == NULL){
        o_empty = 1;
    }

    while(origin.node.next!= NULL){
        origin.node = *origin.node.next;
        if(origin.node.next != NULL){
            ori_node_p = ori_node_p->next;
        }
    }



    counter = 0;

    while(counter<(to-1)){
        destination = *destination.next;
        destination_p = destination_p->next;
        counter++;
    }

    des_node_p = &destination_p->node;

    if(destination.node.value == '\0' || destination.node.suit == '\0'){
        d_empty = 1;
    }

    while(destination.node.next != NULL){
        destination.node = *destination.node.next;
        des_node_p = des_node_p->next;
    }
    int des_value = des_node_p->value;

    if(des_value == 84){
        des_value = 10;
    }else if(des_value == 74){
        des_value = 11;
    }else if(des_value == 81){
        des_value = 12;
    }else if(des_value == 75){
        des_value = 13;
    }else if(des_value == 65){
        des_value = 1;
    }else{
        des_value = des_value-48;
    }

    int ori_value = origin.node.value;
    if(ori_value == 84){
        ori_value = 10;
    }else if(ori_value == 74){
        ori_value = 11;
    }else if(ori_value == 81){
        ori_value = 12;
    }else if(ori_value == 75){
        ori_value = 13;
    }else if(ori_value == 65){
        ori_value = 1;
    }else{
        ori_value = ori_value-48;
    }
    if(d_empty){
       des_node_p->value = ori_node_p->next->value;
       des_node_p->suit = ori_node_p->next->suit;
       des_node_p->next = NULL;
       ori_node_p->next = NULL;


    }else if(destination.node.suit != origin.node.suit){

        if(des_value-ori_value == 1){
            des_node_p->next = ori_node_p->next;
            if(o_empty){
                node_temp->value = ori_node_p->value;
                node_temp->suit = ori_node_p->suit;
                node_temp->next = NULL;
                des_node_p->next = node_temp;
                ori_node_p->value = '\0';
                ori_node_p->suit = '\0';
                ori_node_p->next = NULL;

            }
            ori_node_p->next = NULL;

        }else{
            message = "Invalid move, Cards are not in order\0";
        }
    } else{
        message = "Invalid move, Cards are of same suit\0";
    }

    return message;

}


char* moveCardFromCToC(struct LinkedList** head_ref_l,int from,int to, char value, char suit){
    if(from > 8 || from < 1){
        return "Invalid origin value";
    }else if(to > 8 || to < 1){
        return "Invalid destination value";
    }else if(to == from){
        return "Cannot move card to same column";
    }

    char* message = "OK";
    struct LinkedList origin = **head_ref_l;
    struct LinkedList* origin_p = *head_ref_l;
    struct LinkedList destination = **head_ref_l;
    struct LinkedList* destination_p = *head_ref_l;
    struct Node* des_node_p;
    struct Node* ori_node_p;
    struct Node *node_temp = (struct Node*) malloc(sizeof(struct Node));

    int counter = 0;
    int o_empty = 0;
    int d_empty = 0;
    int no_card = 0;
    int no_consecutive = 0;
    while(counter<(from-1)){
        origin = *origin.next;
        origin_p = origin_p->next;
        counter++;
    }

    ori_node_p = &origin_p->node;

    if(origin.node.next == NULL || (origin.node.value == value && origin.node.suit == suit)){
        o_empty = 1;
        if(origin.node.value == "\0" || origin.node.suit == '\0'){
            no_card = 1;
        }
    }

    while((origin.node.value != value || origin.node.suit != suit) && !no_card){
        if(ori_node_p->next != NULL && (ori_node_p->next->value != value || ori_node_p->next->suit != suit)){
            ori_node_p = ori_node_p->next;
        }
        if(origin.node.next != NULL){
            origin.node = *origin.node.next;
        }


        if (origin.node.next == NULL && (origin.node.value != value || origin.node.suit != suit)){
            no_card = 1;
        }
    }

    if(no_card){
        return "Card was not in the given column";
    }

    node_temp = &origin;


    while(node_temp->next != NULL && !no_consecutive){
        int current = convertValue(node_temp->value);
        int next = convertValue(node_temp->next->value);
        if(node_temp->suit != node_temp->next->suit && current-next == 1){
            node_temp = node_temp->next;
        }else{
            no_consecutive = 1;
        }
    }
    node_temp = NULL;
    if(no_consecutive){
        return "Card in selected column is not legal to move";
    }

    counter = 0;

    while(counter<(to-1)){
        destination = *destination.next;
        destination_p = destination_p->next;
        counter++;
    }

    des_node_p = &destination_p->node;

    if(destination.node.value == '\0' || destination.node.suit == '\0'){
        d_empty = 1;
    }

    while(destination.node.next != NULL){
        destination.node = *destination.node.next;
        des_node_p = des_node_p->next;
    }
    int des_value = convertValue(des_node_p->value);

    int ori_value = convertValue(origin.node.value);

    if(d_empty){
        des_node_p->value = ori_node_p->next->value;
        des_node_p->suit = ori_node_p->next->suit;
        if(ori_node_p->next->next != NULL){
            node_temp = ori_node_p;
            node_temp = node_temp->next->next;
            des_node_p->next = node_temp;
            ori_node_p->next = NULL;

        }else{
            ori_node_p->next = NULL;
        }

        return message;

    }else if(destination.node.suit != origin.node.suit){

        if(des_value-ori_value == 1){
            des_node_p->next = ori_node_p->next;
            if(o_empty){
                node_temp->value = ori_node_p->value;
                node_temp->suit = ori_node_p->suit;
                node_temp->next = NULL;
                des_node_p->next = node_temp;
                ori_node_p->value = '\0';
                ori_node_p->suit = '\0';
                ori_node_p->next = NULL;

            }
            ori_node_p->next = NULL;

        }else{
            message = "Invalid move, Cards are not in order\0";
        }
    } else{
        message = "Invalid move, Cards are of same suit\0";
    }

    return message;

}


void insertAtL(struct LinkedList** head_ref_l,struct Node head_ref, int position){

    struct LinkedList *last = head_ref_l;
    struct LinkedList* new_linkedlist = (struct LinkedList*) malloc(sizeof(struct LinkedList));

    new_linkedlist->node = head_ref;


    int counter = 0;

    while(counter < (position-1)){
        last = last->next;
        counter++;
    }

    new_linkedlist->next = last->next;
    last->next = new_linkedlist;

}


void appendL(struct LinkedList** head_ref_l,struct Node head_ref){

    struct LinkedList *last = head_ref_l;
    struct LinkedList* new_linkedlist = (struct LinkedList*) malloc(sizeof(struct LinkedList));

    //allocate node
    new_linkedlist->node = head_ref;
    new_linkedlist->next = NULL;

    //If the Linked List is empty, then make the new node as head
    if(*head_ref_l == NULL){
        *head_ref_l = new_linkedlist;
        return;
    }
    //Else traverse till the last node
    while(last->next != NULL){
        last = last->next;
    }

    //Change the next of last node
    last->next = new_linkedlist;
    return;
}


void reverseL(struct LinkedList** head_ref_l){
    struct LinkedList* prev = NULL;
    struct LinkedList* current = *head_ref_l;
    struct LinkedList* next = NULL;



    while(current != NULL){
        // Store next
        next = current->next;
        // Move pointers one position ahead.
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref_l = prev;
}

void printListL(struct LinkedList* linkedList){
    struct LinkedList* link = linkedList;
    struct Node* last_p;
    int counter = 1;
    while(link != NULL){
        printf("\n\nColumn: %d\n",counter);
        last_p = &link->node;
        while (last_p != NULL){
            printf("%c%c\n",last_p->value,last_p->suit);
            last_p = last_p->next;
        }
        link = link->next;
        counter++;
    }
}

