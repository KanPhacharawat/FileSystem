#include <stdio.h>
#include <string.h>
#include "module/interface.h"
#include "module/command.h"
#include "struct.h"

int main(void){
    node head;
    strcpy(head.value, "Home");
    head.child = NULL;
    head.next = NULL;

    while(1){
        interface_display();
        int o = command_mainMenu();
        if(o == -1) break;
    }
    printf("%s", head.value);
    interface_end();
    return 0;
}