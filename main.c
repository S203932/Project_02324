#include <stdio.h>
#include "boardlist.h"
#include "ld.h"
#include "process_input.h"
#include <dirent.h>
#include<unistd.h>

int main() {
    empty_board();
    char *m2 = LD(" ");
    char input2[10];
    strcpy(input2, process_input(m2));
    printf("%s", input2);
    return 0;
}
