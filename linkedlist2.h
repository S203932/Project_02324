#include <stdio.h>
#include <stdlib.h>

struct Node;

struct LinkedList;

void pushL (struct LinkedList** head_ref_l, struct Node head_ref);

void clearNewValueL(struct LinkedList** head_ref_l,struct Node head_ref);

void insertAtL(struct LinkedList** head_ref_l,struct Node head_ref, int position);

void appendL(struct LinkedList** head_ref_l,struct Node head_ref);

void reverseL(struct LinkedList** head_ref_l);

void printListL(struct LinkedList* linkedList);

void initializePlayList(struct LinkedList** head_ref_l);

char* moveFromCToC(struct LinkedList** head_ref_l,int from,int to);

