#ifndef STRUCT_H
#define STRUCT_H

typedef struct node{
    char value[50]; // Name of file or folder
    int isFolder; // 1 if folder, 0 if file
    char* content;
    struct node* child;
    struct node* next;
    struct node* parent;
} node;

#endif

void struct_init(node* head);
int findPath(node* current, node* target, char* path);
void struct_buildPath(node* root, node* target, char* path);
