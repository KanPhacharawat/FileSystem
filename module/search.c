#include <stdio.h>
#include "struct.h"


// Function to search specific node
void search_main(hash_table* table, node** current){
    char name[30];
    scanf("%s", name);

    node* n = hash_search(table, name);

    if(n == NULL){
        printf("File/Folder does not exist.\n");
        return;
    }

    *current = n->parent;
}