#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "struct.h"

void save_file_content(node* current, FILE* content_file) {
    if (current->isFolder) return;
    fprintf(content_file, ":::%s\n", current->value);
    if (current->content != NULL) fprintf(content_file, "%s\n", current->content);
    fprintf(content_file, "---END---\n\n");
}

void save_filesystem_structure(node* current, FILE* structure_file) {
    if (current == NULL) return;
    if (current->isFolder) fprintf(structure_file, "FOLDER %s\n", current->value);
    else fprintf(structure_file, "FILE %s\n", current->value);
    if (current->child != NULL) save_filesystem_structure(current->child, structure_file);
    if (current->next != NULL) save_filesystem_structure(current->next, structure_file);
}

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

    fclose(structure_file);
    fclose(content_file);
}
