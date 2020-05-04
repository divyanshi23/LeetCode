class Solution {
public:
    int reverse(int x) {
        if(x==INT_MIN)
            return 0;
        int ans=0;
        int n;
        if(x>=0)
        {
            n=0;
        }
        else
        {
            x=-(x);
            n=1;
        }
        while(x>0)
        {
            int r=x%10;
            x=x/10;
            //ans=ans*10+r        //this can give overflow
            int div=INT_MAX/10;
            if(div<ans)
            {
                return 0;
            }
            else
            {
                ans*=10;
                /*int diff=INT_MAX-r;
                if(diff<ans)
                {
                    return 0;
                }*/
                ans+=r;
            }
            
        }
        if(n)
        {
            ans=-(ans);
        }
        return ans;
    }
};
