#include "traversal.h"
void display(int data)
{
    printf("%d ", data);
}
void main()
{

    bst bst;
    bst.root = NULL;

    for (int i = 0; i < 10; i++)
    {
        Data temp = {i};
        insert(&bst, temp);
    }

    printf("\npreorder :");
    preorder_traversal(&bst, *display);
    printf("\ninorder  :");
    inorder_traversal(&bst, *display);
    printf("\nPostorder:");
    post_order_traversal(&bst, *display);
}