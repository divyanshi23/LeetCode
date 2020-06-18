/*Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.

Note:

The solution set must not contain duplicate triplets.

Example:

Given array nums = [-1, 0, 1, 2, -1, -4],

A solution set is:
[
  [-1, 0, 1],
  [-1, -1, 2]
]*/


class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        set<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i++)
        {
            /*while(i!=0 && nums[i]==nums[i-1] && i<n-2)
                i++;*/
            int a=nums[i];
            int l=i+1;
            int r=n-1;
            
            while(l<r)
            {
                int s=a+nums[l]+nums[r];
                if(s==0)
                {
                    vector<int> v{a,nums[l],nums[r]};
                    ans.insert(v);
                    l++;r--;
                    /*while(nums[l]==nums[l-1] && l<n)
                    {
                        l++;
                    }
                    while(nums[r]==nums[r+1] && r>0)
                    {
                        r--;
                    }*/
                }
                else if(s<0)
                {
                    l++;
                    /*while(nums[l]==nums[l+1] && l<n)
                    {
                        l++;
                    }*/
                }
                else
                {
                    r--;
                    /*while(nums[r]==nums[r-1] && r>0)
                    {
                        r--;
                    }*/
                }
            }
        }
        vector<vector<int>> ansV;
        for(auto i:ans)
        {
            ansV.push_back(i);
        }
        return ansV;
    }
};