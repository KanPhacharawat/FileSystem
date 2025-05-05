#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

// Create a folder under the current node
void create_folder(node* current) {
    getchar();
    char name[100];
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->value, name);
    newNode->isFolder = 1;
    newNode->child = NULL;
    newNode->next = NULL;
    newNode->parent = current;

    if (current->child == NULL) {
        current->child = newNode;
    } else {
        node* temp = current->child;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("Folder %s created.\n", name);
}

// Create a file under the current node
void create_file(node* current) {
    getchar();
    char name[100];
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    node* newNode = (node*)malloc(sizeof(node));
    strcpy(newNode->value, name);
    newNode->isFolder = 0; 
    newNode->child = NULL;
    newNode->next = NULL;
    newNode->parent = current;
    newNode->content = (char*)malloc(1);
    newNode->content[0] = '\0';

    if (current->child == NULL) {
        current->child = newNode;
    } else {
        node* temp = current->child;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }

    printf("File %s created.\n", name);
}
