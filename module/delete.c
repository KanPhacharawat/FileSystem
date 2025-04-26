#include "struct.h"

void delete(node* node){
    if(node == NULL) return;

    delete(node->child);
    delete(node->next);
}