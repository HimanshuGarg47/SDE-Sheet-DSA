#include <iostream>
using namespace std;

bool flag = false;


class Node
{
public:
    int data;
    Node *next;
    Node *prev;

    // Constructor
    Node(int data)
    {
        this->prev = NULL;
        this->data = data;
        this->next = NULL;
    }
};

Node *head = NULL;
Node *head2 = NULL;
Node *tail = NULL;
void InsertAtHead(Node *&head, int d)
{
    Node *temp = new Node(d);
    temp->next = head;
    temp->prev = NULL;

    if ((head) != NULL)
        (head)->prev = temp;

    (head) = temp;
}


void InsertAtEnd(Node *&head, int d)
{
    Node *temp = new Node(d);
    Node *temp1 = head;

    while (temp1->next != NULL)
    {
        temp1 = temp1->next;
    }
    temp->prev = temp1;
    temp1->next = temp;
}


void I()
{
    int number;
    cin >> number;

    if (!flag)
    {
        InsertAtHead(head, number);
        flag = true;
    }
    else
    {
        InsertAtEnd(head, number);
        flag = false;
    }
}

void S()
{
    int i, j;
    cin >> i >> j;
}


void Shuffle(Node *&head, int pos1, int pos2)
{
    Node *Current = head;
    Node *Pos1 = NULL;
    Node *Pos2 = NULL;
    int i = 1;
    int j = 1;
    while (Current != NULL)
    {
        if (i == pos1)
        {

            Pos1 = Current;
            break;
        }

        Current = Current->next;
    }

    // Current = head;

    while (Current != NULL)
    {
        if (j == pos2)
        {
            Pos2 = Current;
            break;
        }

        Current = Current->next;
    }
    Pos1->prev = Pos2->next;
    Pos2->next = Pos1;
    Pos1->prev = Pos2;
}



Node *DL(Node *p, Node *start)
{
    cout << start->data << " ";

    Node *pre = start, *temp = start->next;
    string s = "";

    while (temp && temp != start && temp->prev == pre)
    {
        s += to_string(temp->data);
        pre = temp;
        temp = temp->next;
    }

    for (int i = s.length() - 1; i >= 0; i--)
    {
        cout << (s[i] - 48) << " ";
    }

    cout << start->data << " ";
    if (temp->prev != pre)
        return NULL;
    else
        return DL(pre, temp);
}

void D()
{

    Node *pre = NULL, *temp = head; // cdl -> circular doubled linked list

    while (temp)
    {
        if (temp->prev == NULL)
           { while (temp && (temp->prev == NULL || temp->prev == pre))
            {
                cout << temp->data << " ";
                pre = temp;
                temp = temp->next;
            }}
        else
        {
            temp = DL(pre, temp);
        }

        if (temp && temp->prev != pre)
        {
            temp = DL(pre, temp);
        }

        // if (temp)
        // {
        //     start_cdl = temp;
        //     cout << temp->data << " ";
        //     pre = temp;
        //     temp = temp->next;

        //     while (temp && temp != start_cdl && temp->prev == pre)
        //     {
        //         s += to_string(temp->data);
        //         pre = temp;
        //         temp = temp->next;
        //     }

        //     for (int i = s.length() - 1; i >= 0; i--)
        //     {
        //         cout << (s[i] - 48) << " ";
        //     }

        //     cout << start_cdl->data << " ";

        //     s = "";
        //     start_cdl = pre;
        // }
    }
}



int main()
{
    int op, i = 0;
    cin >> op;

    char c;
    cin >> c;

    while (i < op)
    {
        if (c == 'I')
            I();
        else if (c == 'D')
            D();
        else if (c == 'S')
            S();
        else
            break;
        cin >> c;
        i++;
    }
}