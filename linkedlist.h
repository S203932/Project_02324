#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    struct card *head;
    struct card *tail;
    int size;
} Linked_list;