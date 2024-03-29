#include <bits/stdc++.h>
using namespace std;
struct Node
{
    int data;
    struct Node *next;
    struct Node *bottom;

    Node(int x)
    {
        data = x;
        next = NULL;
        bottom = NULL;
    }
};

/*  Function which returns the  root of
    the flattened linked list. */
Node *mergeTwoLists(Node *a, Node *b)
{

    Node *temp = new Node(0);
    Node *res = temp;

    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else
        {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }

    temp->bottom = a ? a : b;
    // if(a) temp->bottom = a;
    // else temp->bottom = b;

    return res->bottom;
}
Node *flatten(Node *root)
{

    if (root == NULL || root->next == NULL)
        return root;

    // recur for list on right
    root->next = flatten(root->next);

    // now merge
    root = mergeTwoLists(root, root->next);

    // return the root
    // it will be in turn merged with its left
    return root;
}

int main()
{
}