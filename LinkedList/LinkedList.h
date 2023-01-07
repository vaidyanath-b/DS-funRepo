#include <stdio.h>
#include <stdlib.h>

int SIZE = 0;

typedef struct node
{ // basic element of a linked list

    struct node *next;
    int data;

} node;

typedef struct
{ // Wrapper for Node for clarity *optional
    node *head;
} linkedList;

void init(linkedList *li) // Change garbage to NULL
{
    li->head = NULL;
}

node *createNode(int data)
{
    node *temp = (node *)malloc(sizeof(node)); // malloc always returns a pointer to the created instance
    temp->data = data;
    temp->next = NULL;
    return temp;
}

void add(linkedList *li, int data)
{
    node *temp = createNode(data);
    temp->next = li->head;
    li->head = temp;
    SIZE++;
}

void deleteList(linkedList *li) // Memory deallocation
{
    SIZE = 0;
    node *temp = li->head;
    while (temp != NULL && temp != NULL)
    {
        li->head = temp->next;
        free(temp);
        temp = li->head;
    }
}

void input(linkedList *li)
{
    printf("Enter the Elements . Enter 'q' to exit \n");
    char ch;
    int data;
    while (1)
    {
        scanf("%d", &data);
        getchar();
        add(li, data);
        printf("Continue? (y/n) \n");
        scanf("%c", &ch);
        if (ch == 'n')
            break;
    }
}

void displayList(linkedList *li)
{
    node *temp = li->head;
    if (temp == NULL) // if empty exit
        return;
    while (temp->next != NULL) // print until last but one
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("%d \n", temp->data); // print last
}
