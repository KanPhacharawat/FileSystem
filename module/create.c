#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "create.h"

void create_display_structure(node *current, int depth)
{
    if (!current)
        return;

    for (int i = 0; i < depth; i++)
        printf("  ");

    printf("- %s (%s)\n", current->value, current->isFolder ? "Folder" : "File");

    node *child = current->child;
    while (child)
    {
        create_display_structure(child, depth + 1);
        child = child->next;
    }
}

void collect_folders(node *current, node *list[], int *count)
{
    if (!current)
        return;
    if (current->isFolder)
    {
        printf("[%d] %s\n", *count, current->value);
        list[*count] = current;
        (*count)++;
    }
    collect_folders(current->child, list, count);
    collect_folders(current->next, list, count);
}

node *select_folder(node *head)
{
    int count = 0;
    node *list[100];

    printf("\nAvailable Folders:\n");

    collect_folders(head, list, &count);

    if (count == 0)
    {
        printf("No folder available. Creating in root.\n");
        return head;
    }

    printf("Select folder index (-1 for root): ");
    int idx;
    scanf("%d", &idx);
    getchar();

    if (idx == -1)
        return head;
    if (idx >= 0 && idx < count)
        return list[idx];

    printf("Invalid selection. Defaulting to root.\n");
    return head;
}

void create_file(node *head)
{
    node *parent = select_folder(head);

    printf("Enter file name: ");
    char name[100];
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    node *newNode = (node *)malloc(sizeof(node));
    strcpy(newNode->value, name);
    newNode->isFolder = 0;
    newNode->child = NULL;
    newNode->next = NULL;

    if (!parent->child)
    {
        parent->child = newNode;
    }
    else
    {
        node *temp = parent->child;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("File '%s' created.\n", name);
}

void create_folder(node *head)
{
    node *parent = select_folder(head);

    printf("Enter folder name: ");
    char name[100];
    fgets(name, sizeof(name), stdin);
    name[strcspn(name, "\n")] = 0;

    node *newNode = (node *)malloc(sizeof(node));
    strcpy(newNode->value, name);
    newNode->isFolder = 1;
    newNode->child = NULL;
    newNode->next = NULL;

    if (!parent->child)
    {
        parent->child = newNode;
    }
    else
    {
        node *temp = parent->child;
        while (temp->next)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Folder '%s' created.\n", name);
}
