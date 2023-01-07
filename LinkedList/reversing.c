// reversing a linekdList using stack

#include "LinkedList.h"

typedef struct
{
    int top;
    node **nodeItem; // pointer to an array of pointers
} stack;

void push(stack *s, node *current)
{
    if (s->top != SIZE - 1)
        s->nodeItem[++s->top] = current;
}

void reverseList(linkedList *li)
{
    node *temp = li->head;
    stack s;
    s.top = -1;
    s.nodeItem = (node **)malloc(SIZE * sizeof(node *));
    while (temp->next != NULL)
    {
        push(&s, temp);
        temp = temp->next;
    }
    push(&s, temp);
    int t = s.top;
    li->head = s.nodeItem[s.top];
    while (t != 0)
        s.nodeItem[t--]->next = s.nodeItem[t - 1];
    s.nodeItem[t]->next = NULL;

    free(s.nodeItem);
}

void main()
{
    linkedList li;
    init(&li);

    input(&li);
    printf("original list :");
    displayList(&li);

    reverseList(&li);

    printf("reversed list :");
    displayList(&li);

    deleteList(&li);
}
