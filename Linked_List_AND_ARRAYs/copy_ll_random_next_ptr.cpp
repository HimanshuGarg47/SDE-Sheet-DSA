#include <bits/stdc++.h>
using namespace std;

// Definition for a Node.
class Node
{
public:
    int val;
    Node *next;
    Node *random;

    Node(int _val)
    {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution
{
public:
    Node *copyRandomList(Node *head)
    {
        if (!head)
            return NULL;

        // create hash map (node -> new copied node) so that we can
        // easily access to corresponding random pointer in new list
        unordered_map<Node *, Node *> umap;

        Node *temp = head, *prev, *n_head = NULL;

        // traverse existing list and create copied list
        while (temp)
        {
            Node *node = new Node(temp->val);
            umap[temp] = node;

            if (n_head == NULL)
            {
                n_head = node;
                prev = node;
            }

            else
            {
                prev->next = node;
                prev = prev->next;
            }

            temp = temp->next;
        }

        temp = head;
        Node *curr = n_head;

        // update random pointer of every copied node
        while (temp)
        {
            curr->random = umap[temp->random];
            curr = curr->next;
            temp = temp->next;
        }

        return n_head;
    }
};
int main()
{
}