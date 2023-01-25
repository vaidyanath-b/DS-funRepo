#include <stdio.h>
#include <stdlib.h>
typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode;

typedef struct
{
    StackNode *top;
} Stack;

StackNode *createStackNode(int value)
{
    StackNode *temp = (StackNode *)malloc(sizeof(StackNode));
    temp->data = value;
    temp->next = NULL;
    return temp;
}

void push(Stack *s, int value)
{
    StackNode *temp = createStackNode(value);
    if (s->top == NULL)
    {
        s->top = temp;
        return;
    }
    temp->next = s->top;
    s->top = temp;
}

int pop(Stack *s)
{
    if (s->top == NULL)
        return -404;
    StackNode *temp = s->top;
    int tempData = temp->data;
    s->top = s->top->next;
    free(temp);
    return tempData;
}

void display(Stack *s)
{
    StackNode *temp = s->top;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}