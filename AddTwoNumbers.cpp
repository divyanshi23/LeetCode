/*You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1==NULL && l2==NULL)
            return l1;
        if(l1==NULL)
            return l2;
        if(l2==NULL)
            return l1;
        ListNode* temp1=l1;
        ListNode* temp2=l2;
        while(temp1!=NULL && temp2!=NULL)
        {
            temp1->val+=temp2->val;
            if(temp1->val>=10)
            {
                temp1->val-=10;
                if(temp1->next!=NULL)
                {
                    temp1->next->val+=1;
                }
                else
                {
                    ListNode* temp=new ListNode(1);
                    temp1->next=temp;
                }
            }
            temp1=temp1->next;
            temp2=temp2->next;
        }
        
        while(temp1!=NULL && temp1->val>=10)
        {
            temp1->val-=10;
            if(temp1->next==NULL)
            {
                ListNode* temp=new ListNode(1);
                temp1->next=temp;
            }
            else
            {
                temp1->next->val++;
            }
            temp1=temp1->next;
        }
        
                          
        if(temp1==NULL)
        {
            ListNode* temp=l1;
            while(temp->next!=temp1)
            {
                temp=temp->next;
            }
            temp->next=temp2;
        }
        
        return l1;
    }
};