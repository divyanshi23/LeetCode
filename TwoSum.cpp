class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> my_map;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            my_map[nums[i]]=i;
        }
        for(int i=0;i<nums.size();i++)
        {
            if(my_map.find(target-nums[i])!=my_map.end() && my_map.find(target-nums[i])->second!=i)
            {
               
                v.push_back(i);
                v.push_back(my_map.find(target-nums[i])->second);
                return v;
            }
                
        }
        return v;
    }
};
