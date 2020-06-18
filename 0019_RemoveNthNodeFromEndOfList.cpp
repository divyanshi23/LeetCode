/*Given a linked list, remove the n-th node from the end of list and return its head.

Example:

Given linked list: 1->2->3->4->5, and n = 2.

After removing the second node from the end, the linked list becomes 1->2->3->5.
Note:

Given n will always be valid.

Follow up:

Could you do this in one pass?*/

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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(!head)
            return head;
        if(head->next==NULL && n==1)
            return NULL;
        ListNode* n1=head;
        ListNode* n2=head;
        while(n)
        {
            if(n1)
            n1=n1->next;
            n--;
        }
        if(n1==NULL)
        {
            head=n2->next;
            delete n2;
        }
        else
        {
            while(n1 && n1->next!=NULL)
            {
                n1=n1->next;
                n2=n2->next;
            }
            ListNode* temp=n2->next;
            if(temp)
                n2->next=temp->next;
            delete temp;
        }
        return head;
    }
};