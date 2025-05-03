#include "struct.h"

void create_node_from_path(node* root, const char* type, const char* path);
void load_filesystem(node* root);
node* loader_find_node_by_path(node* root, const char* path);
void load_file_content(node* root);
void loader_main(node* root);