#include <bits/stdc++.h>
using namespace std;
int main()
{
}
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution
{
public:
    // My first time approach
    ListNode *reverseKGroup(ListNode *head, int k)
    {
        vector<ListNode *> vec; // for storing starting of reverse group
        ListNode *next, *prev, *curr = head, *pres;
        int no_of_group, count = 0;

        // count number of nodes in LL
        while (curr)
        {
            count++;
            curr = curr->next;
        }

        curr = head;             // point curr to head again
        no_of_group = count / k; // number of groups formed
        while (no_of_group--)
        {
            prev = NULL;
            int j = k;
            while (j--)
            { // below 4 statements are same as reverse LL
                next = curr->next;
                curr->next = prev;
                prev = curr;
                curr = next;
            }
            vec.push_back(prev); // push the starting of reverse LL
        }

        vec.push_back(curr); // if any remaining nodes after forming n groups eg. 1->2->3->4->5 k = 2 || 5 is left so push 5 otherwise NULL

        // Now connect reverse separated groups
        for (int i = 0; i < vec.size() - 1; i++)
        {
            pres = vec[i];
            while (pres->next)
            {
                pres = pres->next;
            }
            pres->next = vec[i + 1];
        }

        // return head of 1st reverse group LL
        return vec[0];
    }



                        // striver optimized approach 1
                    //    https://takeuforward.org/data-structure/reverse-linked-list-in-groups-of-size-k/
//     node* reverseKNodes(node* head,int k) {
//     if(head == NULL||head->next == NULL) return head;
    
//     int length = lengthOfLinkedList(head);
    
//     node* dummyHead = new node(0);
//     dummyHead->next = head;
    
//     node* pre = dummyHead;
//     node* cur;
//     node* nex;
    
//     while(length >= k) {
//         cur = pre->next;
//         nex = cur->next;
//         for(int i=1;i<k;i++) {
//             cur->next = nex->next;
//             nex->next = pre->next;
//             pre->next = nex;
//             nex = cur->next;
//         }
//         pre = cur;
//         length -= k;
//     }
//     return dummyHead->next;
// }
};