#include <string.h>
#include "struct.h"
#include <stdio.h>

void move(node* folder, node* file, node* newF) {
    if (folder == NULL || file == NULL || newF == NULL) return;

    node* temp = folder->child;

    if (temp == file) 
    {
        folder->child = file->next;
    } 
    else 
    {
        while (temp != NULL && temp->next != file) 
        {
            temp = temp->next;
        }
        if (temp != NULL) 
        {
            temp->next = file->next;
        }
        else 
        {
            printf("No target found.\n");
            return;
        }
    }

    file->next = newF->child;
    newF->child = file;
}
