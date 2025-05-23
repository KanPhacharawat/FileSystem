#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

// Function to create node from path for file system structure
void create_node_from_path(node* root, const char* type, const char* path, hash_table* table) {
    char pathCopy[256];
    strcpy(pathCopy, path);
    char* token = strtok(pathCopy, "/");

    node* current = root;
    while (token != NULL) {
        node* temp = current->child;
        int found = 0;

        while (temp) {
            if (strcmp(temp->value, token) == 0) {
                current = temp;
                found = 1;
                break;
            }
            temp = temp->next;
        }

        if (!found) {
            node* newNode = malloc(sizeof(node));
            strcpy(newNode->value, token);
            newNode->isFolder = 1; 
            newNode->content = NULL;
            newNode->child = NULL;
            newNode->next = NULL;
            newNode->parent = current;

            if (!current->child) {
                current->child = newNode;
            } else {
                node* last = current->child;
                while (last->next) last = last->next;
                last->next = newNode;
            }

            current = newNode;
            hash_insert(table, newNode->value, newNode);
        }

        token = strtok(NULL, "/");
    }
    current->isFolder = (strcmp(type, "FOLDER") == 0) ? 1 : 0;
}

// Function to load file system structure
void load_filesystem(node* root, hash_table* table) {
    FILE* fp = fopen("./data/system.txt", "r");
    if (!fp){
        return;
    }

    char type[10], path[256];
    while (fscanf(fp, "%s %[^\n]", type, path) == 2) {
        create_node_from_path(root, type, path, table);
    }

    fclose(fp);
}

// Function to find specific node from path
node* loader_find_node_by_path(node* root, const char* path) {
    char pathCopy[256];
    strcpy(pathCopy, path);
    char* token = strtok(pathCopy, "/");

    node* current = root;
    while (token && current) {
        node* temp = current->child;
        current = NULL;

        while (temp) {
            if (strcmp(temp->value, token) == 0) {
                current = temp;
                break;
            }
            temp = temp->next;
        }

        token = strtok(NULL, "/");
    }

    return current;
}

// Function to load file content
void load_file_content(node* root) {
    FILE* fp = fopen("./data/content.txt", "r");
    if (!fp) return;

    char line[512], path[256], content[10000] = "";
    node* target = NULL;
    int reading = 0;

    while (fgets(line, sizeof(line), fp)) {
        if (strncmp(line, ":::", 3) == 0) {
            if (target && !target->isFolder) {
                target->content = strdup(content);
            }

            strcpy(path, line + 3);
            path[strcspn(path, "\n")] = 0;
            target = loader_find_node_by_path(root, path);
            content[0] = '\0';
            reading = 1;
        } else if (strncmp(line, "---END---", 9) == 0) {
            if (target && !target->isFolder) {
                target->content = strdup(content);
            }
            reading = 0;
            content[0] = '\0';
            target = NULL;
        } else if (reading && target && !target->isFolder) {
            strcat(content, line);
        }
    }

    fclose(fp);
}

// Function to call for load content from .txt file
void loader_main(node* root, hash_table* table) {
    printf("Loading content......\n");
    load_filesystem(root,table);
    load_file_content(root);
}