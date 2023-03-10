#include <stdio.h>
#include <stdlib.h>
#define MAX_SIZE 20

typedef struct
{
    int value;
} Data;

typedef struct node
{
    Data data;
    struct node *left, *right;
} node;

typedef struct bst_stack_node
{
    node *data;
    struct bst_stack_node *next;

} bst_stack_node;

typedef struct
{
    bst_stack_node *top;
} Stack;

bst_stack_node *create_stack_node(node *node)
{
    bst_stack_node *temp = (bst_stack_node *)malloc(sizeof(bst_stack_node));
    temp->data = node;
    temp->next = NULL;
    return temp;
}

void push(Stack *s, node *temp)
{
    bst_stack_node *new_node = create_stack_node(temp);
    if (s->top == NULL)
    {
        s->top = new_node;
        return;
    }
    new_node->next = s->top;
    s->top = new_node;
}

node *pop(Stack *s)
{

    bst_stack_node *temp = s->top;
    node *tempData = temp->data;
    s->top = s->top->next;
    free(temp);
    return tempData;
}

typedef struct
{
    node *root;
} bst;

node *create_node(Data data)
{

    node *temp = (node *)malloc(sizeof(node));
    temp->left = NULL;
    temp->right = NULL;
    temp->data = data;
    return temp;
}

node *peek(Stack s)
{
    return s.top->data;
}

void insert_node(node *root, Data data)
{
    node *temp = create_node(data);

    if (data.value <= root->data.value)
    {
        if (root->left == NULL)
        {
            root->left = temp;
            return;
        }
        insert_node(root->left, data);
    }
    else if (data.value > root->data.value)
    {
        if (root->right == NULL)
        {
            root->right = temp;
            return;
        }
        insert_node(root->right, data);
    }
}

void insert(bst *bst, Data data)
{
    if (bst->root == NULL)
    {
        bst->root = create_node(data);
        return;
    }
    insert_node(bst->root, data);
}
