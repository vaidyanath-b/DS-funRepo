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

void post_order_traversal(bst *bst, void (*process)(int))
{
    Stack s;
    s.top = NULL;
    node *ptr = bst->root;
    node *last = NULL;
    while (s.top || ptr)
    {
        if (ptr)
        {
            push(&s, ptr);
            ptr = ptr->left;
        }
        else
        {
            node *temp = peek(s)->right;
            if (temp)
                ptr = temp;
            else
            {
                temp = pop(&s);
                process(temp->data.value);

                while (s.top && peek(s)->right == temp)
                {
                    temp = pop(&s);
                    process(temp->data.value);
                }
            }
        }
    }
}
