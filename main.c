#include <stdio.h>
#include <string.h>
#include "module/create.h"
#include "module/interface.h"
#include "module/command.h"
#include "module/struct.h"

int main(void){
    node head;
    struct_init(&head);
    node* current = &head;
    char path[50];

    printf("File System [Version 0.0.0.1]\n");
    while(1){
        struct_buildPath(&head, current, path);
        int r = interface_input(path);
        if(r == -1) break;
        else if(r == 3) current = &head;
    }
    return 0;
}