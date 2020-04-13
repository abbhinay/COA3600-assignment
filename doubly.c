/* 
    Solution to problem 3.5
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
    struct Node *prev;
};
void addToHead(struct Node **, int);
void traverse(struct Node **);
void insertAt(struct Node **, int, int);
void main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    head->data = 1;
    head->next = NULL;
    head->prev = NULL;
    addToHead(&head, 2);
    addToHead(&head, 3);
    addToHead(&head, 4);
    addToHead(&head, 5);
    addToHead(&head, 6);
    addToHead(&head, 7);
    addToHead(&head, 8);
    addToHead(&head, 9);
    addToHead(&head, 10);
    insertAt(&head, 4, 20);
    traverse(&head);
}

void addToHead(struct Node **head, int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *tempHead = *head;
    newNode->data = data;
    newNode->next = *head;
    newNode->prev = NULL;
    tempHead->prev = newNode;
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

void insertAt(struct Node **head, int target, int data)
{
    struct Node *temp = *head;
    while (temp->data != target && temp != NULL)
    {
        temp = temp->next;
    }
    if (temp->data == target)
    {
        struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
        newNode->data = data;
        newNode->next = temp->next;
        newNode->prev = temp;
        temp->next = newNode;
        newNode->next->prev = newNode;
    }
    else
    {
        printf("target node not found");
    }
}