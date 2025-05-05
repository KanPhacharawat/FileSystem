#include "struct.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

//  copy a node and its children
node* copy_node(node* original) {
    if (original == NULL) return NULL;

    node* copy = malloc(sizeof(node));
    if (!copy) return NULL;

    strcpy(copy->value, original->value);
    copy->isFolder = original->isFolder;
    copy->parent = NULL;
    copy->next = NULL;

    if (!original->isFolder) {
        if (original->content) {
            copy->content = malloc(strlen(original->content) + 1);
            strcpy(copy->content, original->content);
        } else {
            copy->content = malloc(1);
            copy->content[0] = '\0';
        }
        copy->child = NULL;
    } else {
        copy->child = copy_node(original->child);
        node* temp = copy->child;
        while (temp != NULL) {
            temp->parent = copy;
            temp = temp->next;
        }
        copy->content = NULL;
    }

    return copy;
}

// Copy a node under current with a new name
void copy_main(node* current) {
    char src[30], dest[30];
    scanf("%s %s", src, dest);

    if (current == NULL) return;

    node* temp = current->child;

    while (temp != NULL) {
        if (strcmp(temp->value, src) == 0) {
            node* new_node = copy_node(temp);
            strcpy(new_node->value, dest);
            new_node->next = temp->next;
            temp->next = new_node;
            new_node->parent = current;
            printf("Copied %s as %s\n", src, dest);
            return;
        }
        temp = temp->next;
    }

    printf("Item %s not found.\n", src);
}

