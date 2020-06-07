/*Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).

For example:
Given binary tree [3,9,20,null,null,15,7],
    3
   / \
  9  20
    /  \
   15   7
return its zigzag level order traversal as:
[
  [3],
  [20,9],
  [15,7]
]*/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(root==NULL)
        {
            return ans;
        }
        queue<TreeNode*> q;
        stack<TreeNode*> s;
        int l=1;
        q.push(root);
        q.push(NULL);
        vector<int> v;
        while(!q.empty())
        {
            
            TreeNode* temp=q.front();
            q.pop();
            if(temp==NULL)
            {
                l++;
                while(!s.empty())
                {
                    v.push_back(s.top()->val);
                    s.pop();
                }
                ans.push_back(v);
                v.clear();
                if(!q.empty())
                    q.push(NULL);                
            }
            else
            {
                if(l%2==1)
                    v.push_back(temp->val);
                else
                    s.push(temp);
                if(temp->left)
                    q.push(temp->left);
                if(temp->right)
                    q.push(temp->right);
            }
        }
        return ans;
    }
};