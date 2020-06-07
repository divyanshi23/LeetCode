/*Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:

[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]*/

class Solution {
public:
    
    void helper(vector<string>& v, string s,int leftneeded,int rightneeded)
    {
        if(leftneeded==0 && rightneeded==0)
        {
            v.push_back(s);
            return;
        }
        
        if(leftneeded>0)
            helper(v,s+"(",leftneeded-1,rightneeded);
        
        if(leftneeded<rightneeded)
            helper(v,s+")",leftneeded,rightneeded-1);
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> v;
        helper(v,"",n,n);
        return v;
    }
};