#include <string.h>
#include "struct.h"
#include <stdio.h>

node* find_node_by_path(node** start, const char* path) {
    node* curr = *start;
    char temp[100];
    strcpy(temp, path);

    char* token = strtok(temp, "/");
    while (token != NULL && curr) {
        node* child = curr->child;
        while (child) {
            if (strcmp(child->value, token) == 0) {
                curr = child;
                break;
            }
            child = child->next;
        }
        if (!child) return NULL;
        token = strtok(NULL, "/");
    }
    return curr;
}


void move_main(node* current) {
    char src_name[50], dest_path[100];
    scanf("%s %s", src_name, dest_path);

    if (!current) return;

    node* prev = NULL;
    node* src_node = current->child;

    while (src_node && strcmp(src_node->value, src_name) != 0) {
        prev = src_node;
        src_node = src_node->next;
    }

    if (!src_node) {
        printf("Item not found\n", src_name, current->value);
        return;
    }

    if (prev == NULL) current->child = src_node->next;
    else prev->next = src_node->next;

    node* dest_parent = current;
    node* dest_node = find_node_by_path(&dest_parent, dest_path);

    if (!dest_node || !dest_node->isFolder) {
        printf("Destination not found.\n", dest_path);
        src_node->next = current->child;
        current->child = src_node;
        return;
    }

    src_node->next = dest_node->child;
    dest_node->child = src_node;
    src_node->parent = dest_node;

    printf("Moved %s to %s\n", src_name, dest_node->value);
}

