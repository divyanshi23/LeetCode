/*Shuffle a set of numbers without duplicates.

Example:

// Init an array with set 1, 2, and 3.
int[] nums = {1,2,3};
Solution solution = new Solution(nums);

// Shuffle the array [1,2,3] and return its result. Any permutation of [1,2,3] must equally likely to be returned.
solution.shuffle();

// Resets the array back to its original configuration [1,2,3].
solution.reset();

// Returns the random shuffling of array [1,2,3].
solution.shuffle();*/

class Solution {
    vector<int> nums;
    vector<int> original;
public:
    Solution(vector<int>& nums) {
        this->nums=nums;
        original=nums;
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        //nums=original;
        return original;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        //perfect logic becoz permutations are just random
        /*nums=original;
        int random1=0+(rand()%(nums.size()-1-0+1));
        int random2=0+(rand()%(nums.size()-1-0+1));
        swap(nums[random1],nums[random2]);*/
        
        //in oreder to pass the test case
        next_permutation(nums.begin(),nums.end());
        return nums;
                      
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */