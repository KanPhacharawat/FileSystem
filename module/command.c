#include <stdio.h>
#include "command.h"
#include "create.h"

int command_option(){
    int n;
    scanf("%d", &n);

    if(n > 0 && n < 3) return n;
}

void command_create(int n){
    if(n == 1){
        printf("Create File");
    }else {
        printf("Create Folder");
    }
}

void command_rename(int n){
    if(n == 1){
        printf("Rename File");
    }else {
        printf("Rename Folder");
    }
}

void command_move(int n){
    if(n == 1){
        printf("Move File");
    }else {
        printf("Move Folder");
    }
}

void command_delete(int n){
    if(n == 1){
        printf("Delete File");
    }else {
        printf("Delete Folder");
    }
}

int command_mainMenu(){
    int n;
    printf("Select Main Menu: ");
    scanf("%d", &n);

    if(n == 5) return -1;

    int subn;
    if (n >= 1 && n <= 4) {
        printf("Select 1: File, 2: Folder: ");
        scanf("%d", &subn);
    }

    switch(n){
        case 1:
            command_create(subn);
            break;
        case 2:
            command_rename(subn);
            break;
        case 3:
            command_move(subn);
            break;
        case 4:
            command_delete(subn);
            break;
        default:
            printf("Wrong menu!\n");
            break;
    }
    return 0;
}
