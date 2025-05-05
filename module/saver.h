#include "struct.h"

void build_path(node* n, char* path);
void save_structure(FILE* f, node* current);
void save_content(FILE* f, node* current);
void save_all(node* root);