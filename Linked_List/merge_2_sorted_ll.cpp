#include <bits/stdc++.h>
/************************************************************

    Following is the linked list node structure.

    template <typename T>
    class Node {
        public:
        T data;
        Node* next;

        Node(T data) {
            next = NULL;
            this->data = data;
        }

        ~Node() {
            if (next != NULL) {
                delete next;
            }
        }
    };

************************************************************/
template <typename T>
class Node
{
public:
    T data;
    Node *next;

    Node(T data)
    {
        next = NULL;
        this->data = data;
    }

    ~Node()
    {
        if (next != NULL)
        {
            delete next;
        }
    }
};

Node<int> *sortTwoLists(Node<int> *first, Node<int> *second)
{
    if (!first && !second)
        return first;
    if (first && !second)
        return first;
    if (second && !first)
        return second;
    Node<int> *head, *temp;
    if (first->data < second->data)
    {
        head = first;
        first = first->next;
    }
    else
    {
        head = second;
        second = second->next;
    }
    temp = head;
    while (first && second)
    {
        if (first->data < second->data)
        {
            temp->next = first;
            first = first->next;
            temp = temp->next;
        }
        else
        {
            temp->next = second;
            second = second->next;
            temp = temp->next;
        }
    }

    while (first)
    {
        temp->next = first;
        first = first->next;
        temp = temp->next;
    }

    while (second)
    {
        temp->next = second;
        second = second->next;
        temp = temp->next;
    }

    return head;
    // Write your code here.
}
