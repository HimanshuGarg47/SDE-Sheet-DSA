#include <bits/stdc++.h>
/****************************************************************

    Following is the class structure of the Node class:

       class Node
        {
        public:
            int data;
            Node *next;
            Node(int data)
            {
               this->data = data;
              this->next = NULL;
            }
        };

*****************************************************************/
class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node *findMiddle(Node *head)
{
    if (!head || !head->next)
        return head;

    Node *sl = head, *fs = head->next;
    while (fs && fs->next)
    {
        sl = sl->next;
        fs = fs->next->next;
    }

    if (fs)
        return sl->next;
    return sl;
}