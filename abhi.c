/* 
    Solution to problem 3.3
    Name => Abhinay Kumar
    Roll No => 23
    faculty No => 17ELB175 
*/

#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>

struct Node
{
    int data;
    struct Node *next;
};
void addToHead(struct Node **, int);
void traverse(struct Node **);
void delete (struct Node **, int);
void main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = NULL;
    addToHead(&head, 2);
    addToHead(&head, 3);
    addToHead(&head, 4);
    addToHead(&head, 5);
    addToHead(&head, 6);
    addToHead(&head, 7);
    addToHead(&head, 8);
    addToHead(&head, 9);
    addToHead(&head, 10);
    delete (&head, 1);
    traverse(&head);
}

void addToHead(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

void traverse(struct Node **head)
{
    struct Node *iterator = *head;
    while (iterator != NULL)
    {
        printf("%d \n", iterator->data);
        iterator = iterator->next;
    }
    free(iterator);
}

void delete (struct Node **head, int data)
{
    struct Node *temp = *head;
    if (temp == NULL || temp->next == NULL)
    {
        *head = NULL;
        return;
    }
    if (temp->data == data)
    {
        *head = temp->next;
        return;
    }
    while (temp->next != NULL)
    {
        if (temp->next->data == data)
        {
            temp->next = temp->next->next;
            return;
        }
        temp = temp->next;
    }
    if (temp->data == data)
    {
        struct Node *prev = *head;
        while (prev->next != temp)
        {
            prev = prev->next;
        }
        prev->next = NULL;
        free(prev);
    }
    else
    {
        printf("node not found");
        return;
    }
}