#include <bits/stdc++.h>
using namespace std;

 // Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode() : val(0), next(nullptr) {}
     ListNode(int x) : val(x), next(nullptr) {}
     ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *l3 = NULL, *ans;
        int carry = 0,val = 0;
        while(l1!=NULL && l2!=NULL)
        {
            ListNode *temp = new ListNode;
            val = l1->val + l2->val + carry;
            l1 = l1->next;
            l2 = l2->next;
            temp->val = val%10;
            temp->next = NULL;
            carry = val/10;
            
            if(!l3)
            {
               // temp->next = NULL;
                l3 = temp;
                ans = l3;
            }
            else
            {
                
                l3->next = temp;
                l3 = l3->next;
            }
            
                       
        }
        
        
        while(l1)
        {
            ListNode *temp = new ListNode;
            
           val = l1->val + carry;
             temp->val = val%10;
            carry = val/10;
            
            l1 = l1->next;
            
            l3->next = temp;
            l3 = l3->next;
        }
        
        while(l2)
        {
            ListNode *temp = new ListNode;
            
           val = l2->val + carry;
             temp->val = val%10;
            carry = val/10;
            
            l2 = l2->next;
            
            l3->next = temp;
            l3 = l3->next;
        }
        
        if(carry > 0)
        {
            ListNode *temp = new ListNode;
            
          temp->val = carry;
            temp->next = NULL;
            
            
            l3->next = temp;
            
        }
        return ans;
    }
};