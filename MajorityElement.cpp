/*Given an array of size n, find the majority element. The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty and the majority element always exist in the array.

Example 1:

Input: [3,2,3]
Output: 3
Example 2:

Input: [2,2,1,1,1,2,2]
Output: 2*/

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            if(m.count(nums[i])!=0)
            {
                m[nums[i]]++;
            }
            else
            {
                m[nums[i]]=1;
            }
        }
        int maxN;
        for(auto i:m)
        {
            if(i.second>n/2)
                maxN=i.first;
        }
        return maxN;
    }
};