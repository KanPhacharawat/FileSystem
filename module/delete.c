#include "struct.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void delete_node(node* target) {
    if (target == NULL) return;
    delete_node(target->child);
    delete_node(target->next);
    free(target);
}

void delete_main(node* current) {
    char dest[30];
    scanf("%s", dest);

    if (current == NULL) return;

    node* prev = NULL;
    node* temp = current->child;

    while (temp != NULL) {
        if (strcmp(temp->value, dest) == 0) {
            if (prev == NULL) current->child = temp->next;
            else prev->next = temp->next;

            delete_node(temp);
            printf("Deleted %s\n", dest, current->value);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}
