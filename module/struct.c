#include "struct.h"
#include <string.h>

void struct_init(node* head){
    strcpy(head->value, "Home");
    head->child = NULL;
    head->next = NULL;
}