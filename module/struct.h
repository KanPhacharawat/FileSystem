#ifndef STRUCT_H
#define STRUCT_H

typedef struct node{
    char value[50];
    int isFolder;
    struct node* child;
    struct node* next;
} node;

#endif

void struct_init(node* head);
int findPath(node* current, node* target, char* path);
void struct_buildPath(node* root, node* target, char* path);