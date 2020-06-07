/*Given an array of non-negative integers, you are initially positioned at the first index of the array.

Each element in the array represents your maximum jump length at that position.

Determine if you are able to reach the last index.

 

Example 1:

Input: nums = [2,3,1,1,4]
Output: true
Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last index.
Example 2:

Input: nums = [3,2,1,0,4]
Output: false
Explanation: You will always arrive at index 3 no matter what. Its maximum jump length is 0, which makes it impossible to reach the last index.
 

Constraints:

1 <= nums.length <= 3 * 10^4
0 <= nums[i][j] <= 10^5*/

class Solution {
public:
    
    bool canJumpHelper(vector<int>& nums,int s,int& e,int*& dp)
    {
        
        
        //base case
        if(s>=e)
            return true;
        
        //look up
        if(dp[s]!=-1)
            return dp[s];
        
        //rec call
        int maxJump=nums[s];
        for(int i=maxJump;i>0;i--)
        {
            bool successful=canJumpHelper(nums,s+i,e,dp);
            if(successful)
            {
                dp[s]=1;
                return true;
            }
        }
        dp[s]=0;
        return false;
    }
    
    bool canJump(vector<int>& nums) {
        int s=0;
        int e=nums.size()-1;
        int* dp=new int[e+1];
        
        for(int i=0;i<e;i++)
        {
            dp[i]=-1;
        }
        dp[e]=1;
        for(int i=e-1;i>=0;i--)
        {
            for(int j=nums[i];j>0;j--)
            {
                if(i+j<=e && dp[i+j]==1)
                {
                    dp[i]=1;
                    break;
                }
            }
            if(dp[i]==-1)
                dp[i]=0;
        }
        return dp[0];
        
        /*for(int i=0;i<e;i++)
        {
            dp[i]=-1;
        }
        dp[e]=1;
        return canJumpHelper(nums,s,e,dp);*/
    }
};