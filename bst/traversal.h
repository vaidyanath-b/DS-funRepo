#include "bst.h"
void preorder_traversal(bst *bst, void (*process)(int))
{
    node *root = bst->root;
    Stack s;
    s.top = NULL;
    push(&s, root);

    while (s.top != NULL)
    {
        node *temp = pop(&s);
        if (temp)
        {
            process(temp->data.value);
            if (temp->right)
                push(&s, temp->right);
            if (temp->left)
                push(&s, temp->left);
        }
    }
}

void inorder_traversal(bst *bst, void (*process)(int))
{
    node *temp = bst->root;
    Stack s;
    s.top = NULL;
    while (s.top || temp)
    {
        if (temp)
        {
            push(&s, temp);
            temp = temp->left;
        }
        else
        {
            temp = pop(&s);
            process(temp->data.value);
            temp = temp->right;
        }
    }
}


