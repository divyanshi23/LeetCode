class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if(strs.size()==0)
            return "";
        if(strs.size()==1)
            return strs[0];
        string s1=strs[0];
        for(int i=1;i<strs.size();i++)
        {
            string s2=strs[i];
            int j=0;
            string prefix="";
            while(j<s2.size() && s1[j]==s2[j])
            {
                prefix+=s2[j];
                j++;
            }
            if(j==0)
                return "";
            s1=prefix;
        }
        return s1;
    }
};