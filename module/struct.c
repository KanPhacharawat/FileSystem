#include "struct.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

//default values representing the root folder "Home"
void struct_init(node* head){
    strcpy(head->value, "Home");
    head->isFolder = 1;
    head->child = NULL;
    head->next = NULL;
    head->content = NULL;
    head->parent = NULL;
}
// searches for the path from the current node to the target node
int findPath(node* current, node* target, char* path) {
    if (current == NULL) return 0;
    strcat(path, current->value);

    if (current == target) return 1;

    if (current->child) {
        strcat(path, "/");
        if (findPath(current->child, target, path)) return 1;
        path[strlen(path) - 1] = '\0';
    }
    if (current->next) {
        int len = strlen(current->value);
        path[strlen(path) - len] = '\0';
        if (findPath(current->next, target, path)) return 1;
    }
    return 0;
}
// Builds full path from the root to the target node
void struct_buildPath(node* root, node* target, char* path) {
    path[0] = '\0';
    if (!findPath(root, target, path)) strcpy(path, "Node not found");
}

// Function to hash a string using djb2 algorithm
unsigned int hash_func(const char* key) {
    unsigned long hash = 5381;
    int c;
    while ((c = *key++))
        hash = ((hash << 5) + hash) + c;
    return hash % HASH_SIZE;
}

// Function to insert new item into hash table
void hash_insert(hash_table* table, const char* key, node* value) {
    unsigned int index = hash_func(key);

    hash_entry* current = table->buckets[index];
    while (current) {
        if (strcmp(current->key, key) == 0) {
            current->value = value;
            return;
        }
        current = current->next;
    }

    hash_entry* new_entry = malloc(sizeof(hash_entry));
    if (!new_entry) {
        printf("Can't create new entry\n");
        return;
    }

    strcpy(new_entry->key, key);
    new_entry->value = value;
    new_entry->next = table->buckets[index];
    table->buckets[index] = new_entry;
}

// Function to search specific key in the hash table
node* hash_search(hash_table* table, const char* key) {
    unsigned int index = hash_func(key);
    hash_entry* current = table->buckets[index];
    while (current != NULL) {
        if (strcmp(current->key, key) == 0) {
            return current->value;
        }
        current = current->next;
    }
    return NULL;
}

// Function to create new hash table
hash_table* create_table() {
    hash_table* table = (hash_table*)malloc(sizeof(hash_table));
    if(table == NULL) return NULL;
    for (int i = 0; i < HASH_SIZE; i++)
        table->buckets[i] = NULL;
    return table;
}
