#include "struct.h"
#include <string.h>

void struct_init(node* head){
    strcpy(head->value, "Home");
    head->isFolder = 1;
    head->child = NULL;
    head->next = NULL;
}

int findPath(node* current, node* target, char* path) {
    if (current == NULL) return 0;
    strcat(path, current->value);

    if (current == target) return 1;

    if (current->child) {
        strcat(path, "/");
        if (findPath(current->child, target, path)) return 1;
        path[strlen(path) - 1] = '\0';
    }
    if (current->next) {
        int len = strlen(current->value);
        path[strlen(path) - len] = '\0';
        if (findPath(current->next, target, path)) return 1;
    }
    return 0;
}

void struct_buildPath(node* root, node* target, char* path) {
    path[0] = '\0';
    if (!findPath(root, target, path)) strcpy(path, "Node not found");
}