/*Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.

You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.

Example 1:

Input: 1->2->3->4->5->NULL
Output: 1->3->5->2->4->NULL
Example 2:

Input: 2->1->3->5->6->4->7->NULL
Output: 2->3->6->7->1->5->4->NULL
 

Constraints:

The relative order inside both the even and odd groups should remain as it was in the input.
The first node is considered odd, the second node even and so on ...
The length of the linked list is between [0, 10^4].*/

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
    
    //Approach 1:
    ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* oHead=head;
        ListNode* eHead=head->next;
        ListNode* eptr=head->next;    //2,4,6...
        ListNode* optr=head;   //1,3,5...
        //ListNode* oTail=head;
        int i=3;
        ListNode* temp=head->next->next;
        while(temp!=NULL)
        {
            if(i&1)
            {
                optr->next=temp;
                optr=optr->next;
            }
            else
            {
                eptr->next=temp;
                if(eptr->next)
                eptr=eptr->next;
            }
            temp=temp->next;
            i++;
        }
        eptr->next=NULL;
        optr->next=eHead;
        return oHead;
    }
    
    //Approach 2:
    /*ListNode* oddEvenList(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode* o=head;
        ListNode* e=head->next;
        ListNode* eHead=e;
        while(o->next!=NULL && e->next!=NULL)
        {
            o->next=e->next;
            o=o->next;
            e->next=o->next;
            e=e->next;
            
        }
        o->next=eHead;
        return head;
    }*/
};