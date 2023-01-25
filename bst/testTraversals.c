#include "traversal.h"
void display(int data)
{
    printf("%d ", data);
}
void main()
{

    bst bst;
    Data a = {1};
    Data b = {2};
    Data c = {3};
    Data d = {4};
    node *one = create_node(c);
    node *two = create_node(b);
    node *three = create_node(d);
    node *four = create_node(a);
    one->left = two;
    one->right = three;
    two->left = four;

    bst.root = one;
    printf("\npreorder :");
    preorder_traversal(&bst, *display);
    printf("\ninorder  :");
    inorder_traversal(&bst, *display);
    printf("\nPostorder:");
    post_order_traversal(&bst, *display);
}