#include "struct.h"
#include <string.h>

void struct_init(node* head){
    strcpy(head->value, "Home");
    head->isFolder = 1;
    head->child = NULL;
    head->next = NULL;
}