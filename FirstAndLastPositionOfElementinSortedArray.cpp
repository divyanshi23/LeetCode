/*Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:

Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]
Example 2:

Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n=nums.size();
        
        if(n==0)
        {
            vector<int> v{-1,-1};
            return v;
        }
        vector<int> ans;
        //using stl
        /*int lower=lower_bound(nums.begin(),nums.end(),target)-nums.begin();
        int upper=upper_bound(nums.begin(),nums.end(),target)-nums.begin();
        if(lower<n && nums[lower]==target)
        {
            ans.push_back(lower);
            ans.push_back(upper-1);
        }
        else
        {
            ans.push_back(-1);
            ans.push_back(-1);
        }
        return ans;*/
        
        //using self implemented binary search
        int s=0,e=n-1;
        int la=-1,ua=-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(nums[mid]==target)
            {    
                la=mid;
                e=mid-1;
            }
            else if(nums[mid]>target)
            {
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        ans.push_back(la);
        s=0;e=n-1;
        while(s<=e)
        {
            int mid=(s+e)/2;
            if(nums[mid]==target)
            {    
                ua=mid;
                s=mid+1;
            }
            else if(nums[mid]>target)
            {
                e=mid-1;
            }
            else
            {
                s=mid+1;
            }
        }
        ans.push_back(ua);
        return ans;
    }
};