/*Given a linked list, determine if it has a cycle in it.

To represent a cycle in the given linked list, we use an integer pos which represents the position (0-indexed) in the linked list where tail connects to. If pos is -1, then there is no cycle in the linked list.

 

Example 1:

Input: head = [3,2,0,-4], pos = 1
Output: true
Explanation: There is a cycle in the linked list, where tail connects to the second node.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        //unordered_map<ListNode*,int> m;
        ListNode* n1=head;
        ListNode* n2=head;
        while(n1 && n2 && n2->next)
        {
            n1=n1->next;
            n2=n2->next->next;
            if(n1==n2)
                return true;
        }
        
        return false;     
    }
};