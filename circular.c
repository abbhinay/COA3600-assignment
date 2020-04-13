/* 
    Solution to problem 3.4
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
int checkIfCircular(struct Node **);
void deleteCircular(struct Node **, int);
void iterator(struct Node **);
void main()
{
    struct Node *head = (struct Node *)malloc(sizeof(struct Node));
    struct Node *second = (struct Node *)malloc(sizeof(struct Node));
    struct Node *third = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fourth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *fifth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *sixth = (struct Node *)malloc(sizeof(struct Node));
    struct Node *seventh = (struct Node *)malloc(sizeof(struct Node));
    struct Node *eight = (struct Node *)malloc(sizeof(struct Node));
    struct Node *nine = (struct Node *)malloc(sizeof(struct Node));
    struct Node *ten = (struct Node *)malloc(sizeof(struct Node));
    head->data = 1;
    second->data = 2;
    third->data = 3;
    fourth->data = 4;
    fifth->data = 5;
    sixth->data = 6;
    seventh->data = 7;
    eight->data = 8;
    nine->data = 9;
    ten->data = 10;
    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = sixth;
    sixth->next = seventh;
    seventh->next = eight;
    eight->next = nine;
    nine->next = ten;
    ten->next = head;
    if (checkIfCircular(&head) == 1)
    {
        deleteCircular(&head, 4);
    }
    iterator(&head);
}

int checkIfCircular(struct Node **head)
{
    struct Node *iterator = *head;
    iterator = iterator->next;
    while (iterator != *head && iterator != NULL)
    {
        iterator = iterator->next;
    }
    if (iterator == *head)
    {
        return 1;
    }
    else
    {
        return 0;
    }
    free(iterator);
}

void deleteCircular(struct Node **head, int data)
{
    struct Node *temp = *head;
    if (temp == NULL || temp->next == NULL)
    {
        *head = NULL;
        return;
    }
    if (temp->data == data)
    {
        temp->data = temp->next->data;
        temp->next = temp->next->next;
        return;
    }
    temp = temp->next;
    while (temp != *head)
    {
        if (temp->data == data)
        {
            temp->data = temp->next->data;
            temp->next = temp->next->next;
            return;
        }
        temp = temp->next;
    }
    free(temp);
}

void iterator(struct Node **head)
{
    struct Node *temp = *head;
    printf("%d \n", temp->data);
    temp = temp->next;
    while (temp != *head)
    {
        printf("%d \n", temp->data);
        temp = temp->next;
    }
}