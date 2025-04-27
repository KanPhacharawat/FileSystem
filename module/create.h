#ifndef CREATE_H
#define CREATE_H

#include "struct.h"

void create_file(node *head);
void create_folder(node *head);
void create_display_structure(node *current, int depth);
node* select_folder(node *head);

#endif
