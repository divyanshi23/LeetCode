/*Given n non-negative integers representing an elevation map where the width of each bar is 1, 
compute how much water it is able to trap after raining.

Example:

Input: [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
*/

class Solution {
public:
    int trap(vector<int>& height) {
    
        int n=height.size();
        if(n==0 || n==1)
            return 0;
        int* l=new int[n];
        int* r=new int[n];
        l[0]=max(0,height[0]);
        r[n-1]=max(0,height[n-1]);
        for(int i=n-2;i>=0;i--)
        {
            r[i]=max(height[i],r[i+1]);
        }
        for(int i=1;i<n;i++)
        {
            l[i]=max(l[i-1],height[i]);
        }
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=(min(l[i],r[i])-height[i]);
        }
        return ans;
    }
};