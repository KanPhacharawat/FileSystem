#include "struct.h"

void create_node_from_path(node* root, const char* type, const char* path, hash_table* table);
void load_filesystem(node* root, hash_table* table);
node* loader_find_node_by_path(node* root, const char* path);
void load_file_content(node* root);
void loader_main(node* root, hash_table* table);