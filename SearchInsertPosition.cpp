/*Given a sorted array and a target value, return the index if the target is found. If not, return the index where it would be if it were inserted in order.

You may assume no duplicates in the array.*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int j=0;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
            {
                return i;
            }
            else if(nums[i]<target)
            {
                j++;
            }
            else
            {
                return j;
            }

        }
        return j;
    }
};