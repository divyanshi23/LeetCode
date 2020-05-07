/*Implement int sqrt(int x).

Compute and return the square root of x, where x is guaranteed to be a non-negative integer.

Since the return type is an integer, the decimal digits are truncated and only the integer part of the result is returned.*/

class Solution {
public:
    int mySqrt(int x) {
        if(x==1)
            return 1;
        int s=0;int e=x;
        int ans=0;
        while(s<=e)
        {
            long long int mid=(s+e)/2;
            long long sq=mid*mid;
            if(sq==x)
            {
                ans=mid;
                return mid;
            }
            else if(sq<x)
            {
                ans=mid;
                s=mid+1;
            }
            else
            {
                e=mid-1;
            }
        }
        return ans;
    }
        
};