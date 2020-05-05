class Solution {
public:
    
    int search(char s)
    {
        if(s=='I')
            return 1;
        else if(s=='V')
            return 5;
        else if( s=='X')
            return 10;
        else if(s=='L')
            return 50;
        else if(s=='C')
            return 100;
        else if(s=='D')
            return 500;
        else if(s=='M')
            return 1000;
        return 0;
    }
    int romanToInt(string s) {
        int ans=0;
        for(int i=0;i<s.size();i++)
        {
            if(search(s[i+1])>search(s[i]))
            {
                ans=ans+search(s[i+1])-search(s[i]);
                i++;
            }
            else
            {
                ans=ans+search(s[i]);
            }
        }
        return ans;
    }
};