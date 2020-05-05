class Solution {
public:
    bool isValid(string s) {
        stack<char> l;
        for(int i=0;i<s.size();i++)
        {
            char t;
            if(!l.empty())
                t=l.top();
            else
                t='\0';
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
            {
                l.push(s[i]);
            }
            else if((t=='(' && s[i]==')') || (t=='{' && s[i]=='}') || (t=='[' && s[i]==']'))
            {
                    l.pop();
            }
            else
                return false;
        }
        if(l.empty())
            return true;
        else
            return false;
    }
};