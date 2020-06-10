/*Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.

Example 1:

Input: [3,2,1,5,6,4] and k = 2
Output: 5
Example 2:

Input: [3,2,3,1,2,4,5,5,6] and k = 4
Output: 4
Note:
You may assume k is always valid, 1 ≤ k ≤ array's length.*/

class Solution {
public:
    
    //Approach 1: O(N logN) time
    /*int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        return nums[n-k];
    }*/
    
    //Approach 2: O(N logN) time and O(N) space
    /*int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++)
        {
            pq.push(nums[i]);
        }
        for(int i=1;i<k;i++)
        {
            pq.pop();
        }
        return pq.top();
    }*/
    
    //Approach 3: O(k+(n-k)Logk) time and O(LogK) space
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int i=0;i<k;i++)
        {
            pq.push(nums[i]);
        }
        for(int i=k;i<n;i++)
        {
            if(nums[i]>pq.top())
            {
                //pq[0]=nums[i];
                pq.pop();
                pq.push(nums[i]);
                //heapify(0);
            }
        }
        return pq.top();
    }
};