#ifndef STRUCT_H
#define STRUCT_H

#define HASH_SIZE 101

typedef struct node{
    char value[50]; // Name of file or folder
    int isFolder; // 1 if folder, 0 if file
    char* content;
    struct node* child;
    struct node* next;
    struct node* parent;
} node;

typedef struct hash_entry {
    char key[100];     
    struct node* value;
    struct hash_entry* next;
} hash_entry;

typedef struct {
    hash_entry* buckets[100];
} hash_table;

#endif

void struct_init(node* head);
int findPath(node* current, node* target, char* path);
void struct_buildPath(node* root, node* target, char* path);
unsigned int hash_func(const char* key);
void hash_insert(hash_table* table, const char* key, node* value);
node* hash_search(hash_table* table, const char* key);
hash_table* create_table();