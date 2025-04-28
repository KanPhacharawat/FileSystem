#include <stdio.h>
#include <string.h>

int command_read(char* comm){
    if(strcmp(comm, "exit") == 0){
        return -1;
    }else if(strcmp(comm, "pwd") == 0){
        return 1;
    }else if(strcmp(comm, "help") == 0){
        return 2;
    }else if(strcmp(comm, "home") == 0){
        return 3;
    }
    return 0;
}