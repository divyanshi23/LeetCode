/*Given an integer array nums, 
find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.*/

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        int minele=INT_MIN;
        int sum=0;
        for(int i=0;i<nums.size();i++)
        {
            minele=max(minele,nums[i]);
            sum+=nums[i];
            if(sum<=0)
            {
                sum=0;
            }
            ans=max(ans,sum);
        }
        if(ans==0)
        {
            return minele;
        }
        else
        {
            return ans;
        }
    }
};