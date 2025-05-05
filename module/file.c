#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "struct.h"

// Display file content by name
void file_view(node* current){
    char name[30];
    scanf("%s", name);

    node* temp = current->child;
    while (temp != NULL) {
        if (!temp->isFolder && strcmp(temp->value, name) == 0) {
            printf("%s\n",temp->content);
            return;
        }
        temp = temp->next;
    }

    printf("%s not found.\n", name);
}

// Edit file content
void file_edit(node* current) {
    char name[30];
    scanf("%s", name);
    getchar();

    node* temp = current->child;
    while (temp != NULL) {
        if (!temp->isFolder && strcmp(temp->value, name) == 0) {
            printf("Enter new content for %s (end with a single line containing only `::end`)\n", name);

            char buffer[10000] = ""; 
            char line[256];
            while (1) {
                fgets(line, sizeof(line), stdin);
                if (strcmp(line, "::end\n") == 0) break;
                strcat(buffer, line);
            }

            free(temp->content); 
            temp->content = (char*)malloc(strlen(buffer) + 1);
            strcpy(temp->content, buffer);

            printf("%s updated.\n", name);
            return;
        }
        temp = temp->next;
    }

    printf("%s not found.\n", name);
}
