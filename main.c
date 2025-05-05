#include <stdio.h>
#include <string.h>
#include "module/create.h"
#include "module/interface.h"
#include "module/command.h"
#include "module/struct.h"
#include "module/loader.h"
#include "module/saver.h"

//initiate struct
int main(void){
    node head;
    hash_table* table = create_table();
    struct_init(&head);
    loader_main(&head, table);
    node* current = &head;
    char path[50];

    printf("File System [Version 0.0.0.1]\n");
    
    // Main loop for input and command execution
    while(1){
        struct_buildPath(&head, current, path);
        int r = interface_input(path, &current, table);
        if(r == -1) break;
        else if(r == 3) current = &head;
        else if(r == 4) create_folder(current, table);
        else if(r == 5) create_file(current, table);
    }
    save_all(&head);
    return 0;
}
