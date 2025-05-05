#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"


// Saves content of a file node to the content file
void save_file_content(node* current, FILE* content_file) {
    if (current->isFolder) return;
    fprintf(content_file, ":::%s\n", current->value);
    if (current->content != NULL) fprintf(content_file, "%s\n", current->content);
    fprintf(content_file, "---END---\n\n");
}

// Saves the structure of the filesystem to the structure file
void save_filesystem_structure(node* current, FILE* structure_file) {
    if (current == NULL) return;
    if (current->isFolder) fprintf(structure_file, "FOLDER %s\n", current->value);
    else fprintf(structure_file, "FILE %s\n", current->value);
    if (current->child != NULL) save_filesystem_structure(current->child, structure_file);
    if (current->next != NULL) save_filesystem_structure(current->next, structure_file);
}

// Main function that handle saving the filesystem structure and file content
void saver_main(node* root) {
    FILE* structure_file = fopen("./data/system.txt", "w");
    FILE* content_file = fopen("./data/content.txt", "w");

    if (structure_file == NULL || content_file == NULL) return;

    save_filesystem_structure(root, structure_file);

    node* temp = root->child;
    while (temp != NULL) {
        save_file_content(temp, content_file);
        temp = temp->next;
    }
}

// Helper function to create a path
void build_path(node* n, char* path) {
    if (n->parent == NULL || strcmp(n->parent->value, "Home") == 0) {
        strcpy(path, n->value);
        return;
    }
    char temp[1024];
    build_path(n->parent, temp);
    sprintf(path, "%s/%s", temp, n->value);
}

// Sub function to save file system structure
void save_structure(FILE* f, node* current) {
    if (!current) return;

    if (strcmp(current->value, "Home") != 0) {
        char path[1024];
        build_path(current, path);
        fprintf(f, "%s %s\n", current->isFolder ? "FOLDER" : "FILE", path);
    }

    save_structure(f, current->child);
    save_structure(f, current->next);
}

// Sub function to save file content
void save_content(FILE* f, node* current) {
    if (!current) return;

    if (!current->isFolder && current->content[0] != '\0') {
        size_t len = strlen(current->content);
        while (len > 0 && (current->content[len - 1] == '\n' || current->content[len - 1] == '\r' || current->content[len - 1] == ' ')) {
            current->content[len - 1] = '\0';
            len--;
        }

        char path[1024];
        build_path(current, path);
        fprintf(f, ":::%s\n", path);
        fprintf(f, "%s\n", current->content);
        fprintf(f, "---END---\n\n");
    }

    save_content(f, current->child);
    save_content(f, current->next);
}

// Function to call for save content to .txt file
void save_all(node* root) {
    FILE* f_struct = fopen("./data/system.txt", "w");
    FILE* f_content = fopen("./data/content.txt", "w");

    if (!f_struct || !f_content) {
        return;
    }

    save_structure(f_struct, root->child); 
    save_content(f_content, root->child);

    fclose(f_struct);
    fclose(f_content);
}