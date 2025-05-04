#include <string.h>
#include <stdio.h>
#include "struct.h"

// Rename child node 
void rename_main(node* file) {
    char dest[30], name[30];
    scanf("%s %s", dest, name);

    node* temp = file->child;
    while (temp != NULL) {
        if (strcmp(temp->value, dest) == 0) {
            strcpy(temp->value, name);
            printf("Renamed %s to %s\n", dest, name);
            return;
        }
        temp = temp->next;
    }
}
