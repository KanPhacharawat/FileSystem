#include <stdio.h>
#include <string.h>
#include "module/create.h"
#include "module/interface.h"
#include "module/command.h"
#include "struct.h"

int main(void){
    node head;
    struct_init(&head);

    while(1){
        interface_display();
        int o = command_mainMenu();
        if(o == -1) break;
    }
    interface_end();
    printf("%s", head.value);
    return 0;
}