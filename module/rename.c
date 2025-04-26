#include <string.h>
#include "struct.h"

void rename(node* file, char* name){
    strcpy(file->value, name);
}