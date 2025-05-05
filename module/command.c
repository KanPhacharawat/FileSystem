#include <stdio.h>
#include <string.h>
#include "struct.h"

void command_navigate(node** current) {
    char name[30];
    scanf("%s", name); // Read the name of the folder to navigate to


    if (strcmp(name, "..") == 0) {
        if ((*current)->parent != NULL) {
            *current = (*current)->parent;
        }
        return;
    }

    node* temp = (*current)->child;
    while (temp != NULL) {
        if (temp->isFolder && strcmp(temp->value, name) == 0) {
            *current = temp;
            return;
        }
        temp = temp->next;
    }
}
// Return command code for a given command string
int command_read(char* comm){
    if(strcmp(comm, "exit") == 0){
        return -1;
    }else if(strcmp(comm, "pwd") == 0){
        return 1;
    }else if(strcmp(comm, "help") == 0){
        return 2;
    }else if(strcmp(comm, "home") == 0){
        return 3;
    }else if(strcmp(comm, "mkdir") == 0){
        return 4;
    }else if(strcmp(comm, "touch") == 0){
        return 5;
    }else if(strcmp(comm, "ls") == 0){
        return 6;
    }else if(strcmp(comm, "cd") == 0){
        return 7;
    }else if(strcmp(comm, "rn") == 0){
        return 8;
    }else if(strcmp(comm, "rm") == 0){
        return 9;
    }else if(strcmp(comm, "cp") == 0){
        return 10;
    }else if(strcmp(comm, "mv") == 0){
        return 11;
    }else if(strcmp(comm, "cat") == 0){
        return 12;
    }else if(strcmp(comm, "nano") == 0){
        return 13;
    }else if(strcmp(comm, "search") == 0){
        return 14;
    }
    return 0;
}
