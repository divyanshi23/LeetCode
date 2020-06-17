/*Given a set of distinct integers, nums, return all possible subsets (the power set).

Note: The solution set must not contain duplicate subsets.

Example:

Input: nums = [1,2,3]
Output:
[
  [3],
  [1],
  [2],
  [1,2,3],
  [1,3],
  [2,3],
  [1,2],
  []
]*/

class Solution {
public:
    
    //vector<vector<int>> ans;
    
    vector<vector<int>> helper(vector<int>& nums,int s,int e)
    {
        vector<vector<int>> ans;
        vector<int> v;
        if(s>e)
        {
            ans.push_back(v);
            return ans;
        }
        /*if(s==e)
        {
            v.push_back(nums[s]);
            ans.push_back(v);
        }*/
        ans=helper(nums,s,e-1);
        int n=ans.size();
        for(int i=0;i<n;i++)
        {
            vector<int> temp=ans[i];
            temp.push_back(nums[e]);
            ans.push_back(temp);
        }
        return ans;
    }
    
    vector<vector<int>> subsets(vector<int>& nums) {
        return helper(nums,0,nums.size()-1);
    }
};