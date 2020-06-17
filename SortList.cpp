/*Sort a linked list in O(n log n) time using constant space complexity.

Example 1:

Input: 4->2->1->3
Output: 1->2->3->4
Example 2:

Input: -1->5->3->4->0
Output: -1->0->3->4->5*/

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
    
    ListNode* partition(ListNode* head)
    {
        if(head==NULL || head->next==NULL)
            return NULL;
        
        ListNode* slow=head;
        ListNode* fast=head;
        
        while(fast!=NULL && fast->next)
        {
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* p=head;
        while(p->next!=slow)
        {
            p=p->next;
        }
        p->next=NULL;
        return slow;
    }
    
    ListNode* mergeLL(ListNode* h1,ListNode* h2)
    {
        if(h1==NULL)
            return h2;
        if(h2==NULL)
            return h1;
        ListNode* head;
        if(h1->val<h2->val)
        {
            head=h1;
            h1=h1->next;
        }
        else
        {
            head=h2;
            h2=h2->next;
        }
        ListNode* temp=head;
        while(h1!=NULL && h2!=NULL)
        {
            if(h1->val<h2->val)
            {
                temp->next=h1;
                temp=temp->next;
                h1=h1->next;
            }
            else
            {
                temp->next=h2;
                h2=h2->next;
                temp=temp->next;
            }
        }
        
        if(h1!=NULL)
            temp->next=h1;
        if(h2!=NULL)
            temp->next=h2;
        return head;
        
    }
    
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* a=head;
        ListNode* b=partition(head);
        ListNode* head1=sortList(a);
        ListNode* head2=sortList(b);
        return mergeLL(head1,head2);
    }
};