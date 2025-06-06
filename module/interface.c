#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "command.h"
#include "struct.h"
#include "rename.h"
#include "delete.h"
#include "copy.h"
#include "move.h"
#include "file.h"
#include "search.h"

// Convert command string to lowercase
void interface_cleancomm(char* comm){
    for(int i = 0; i < strlen(comm); i++){
        comm[i] = tolower(comm[i]);
    }
}

// List contents
void interface_list(node* current){
    if(current->child == NULL) return;

    node* temp = current->child;
    while (temp != NULL) {
        printf("%s\n", temp->value);
        temp = temp->next;
    }
}

// Process a command and return its type
int interface_input(char* path, node** current, hash_table* table){
    char comm[10];
    printf("%s> ", path);
    scanf("%s", comm);
    interface_cleancomm(comm);
    int r = command_read(comm);

    if(r == 1) printf("Path\n----\n%s\n", path);
    else if(r == 2){
        printf("mkdir\tCreate folder.\n");
        printf("touch\tCreate file.\n");
        printf("rn\tRename directory.\n");
        printf("rm\t Remove directory.\n");
        printf("mv\tMove directory.\n");
        printf("cp\tDuplicate directory.\n");
        printf("nano\tEdit file.\n");
        printf("cat\tView file content.\n");
        printf("cd\tChange the current directory.\n");
        printf("ls\tDisplay the current directory.\n");
        printf("pwd\tDisplay the current directory.\n");
        printf("home\tQuickly return to root directory.\n");
        printf("search\tFind specific file/folder by name.\n");
        printf("exit\tTerminate program.\n");
    }else if(r == 6) interface_list(*current);
    else if(r == 7) command_navigate(current);
    else if(r == 8) rename_main(*current);
    else if(r == 9) delete_main(*current);
    else if(r == 10) copy_main(*current);
    else if(r == 11) move_main(*current);
    else if(r == 12) file_view(*current);
    else if(r == 13) file_edit(*current);
    else if(r == 13) file_edit(*current);
    else if(r == 14) search_main(table,current);
    return r;
}
