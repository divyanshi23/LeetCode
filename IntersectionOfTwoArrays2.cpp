/*Given two arrays, write a function to compute their intersection.

Example 1:

Input: nums1 = [1,2,2,1], nums2 = [2,2]
Output: [2,2]
Example 2:

Input: nums1 = [4,9,5], nums2 = [9,4,9,8,4]
Output: [4,9]
Note:

Each element in the result should appear as many times as it shows in both arrays.
The result can be in any order.*/

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> v;
        if(nums1.size()==0 || nums2.size()==0)
            return v;
        unordered_map<int,int> m;
        for(int i=0;i<nums1.size();i++)
        {
            if(m.count(nums1[i])!=0)
            {
                m[nums1[i]]++;
            }
            else
                m[nums1[i]]=1;
        }
        for(int i=0;i<nums2.size();i++)
        {
            if(m.count(nums2[i])!=0 && m[nums2[i]]>0)
            {
                v.push_back(nums2[i]);
                m[nums2[i]]--;
            }
        }
        return v;
    }
};