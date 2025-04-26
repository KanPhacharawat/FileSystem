#ifndef STRUCT_H
#define STRUCT_H

typedef struct node{
    char value[50];
    int isFolder;
    struct node* child;
    struct node* next;
} node;

#endif