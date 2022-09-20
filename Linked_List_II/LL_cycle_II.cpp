#include <bits/stdc++.h>
using namespace std;


// https://leetcode.com/problems/linked-list-cycle-ii/
// Definition for singly-linked list.
struct ListNode
{
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// using two pointers and some more login T(n) + S(1)
class Solution
{
public:
    ListNode *detectCycle(ListNode *head)
    {

        if (!head)
            return NULL;

        // unordered_set<ListNode *> uset;
        ListNode *sl = head, *ft = head;

        while (sl && ft && ft->next && sl != ft)
        {
            sl = sl->next;
            ft = ft->next->next;
        }
        if (sl == ft)
        {
            while (head != ft)
            {
                head = head->next;
                ft = ft->next;
            }
            return head;
        }
        return NULL;
    }
};


// using hashing T(n)+ S(n)
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
        if(!head)
            return NULL;
        
        unordered_set<ListNode *> uset;
        ListNode *sl = head;
      
        
        while(sl)
        {
           if(uset.find(sl)!=uset.end())
               return sl;
            uset.insert(sl);
            sl = sl->next;
            
        }
        return NULL;
    }
};
int main()
{
}
