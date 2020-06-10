/*Given an array nums of n integers where n > 1,  return an array output such that output[i] is equal to the product of all the elements of nums except nums[i].

Example:

Input:  [1,2,3,4]
Output: [24,12,8,6]
Constraint: It's guaranteed that the product of the elements of any prefix or suffix of the array (including the whole array) fits in a 32 bit integer.

Note: Please solve it without division and in O(n).

Follow up:
Could you solve it with constant space complexity? (The output array does not count as extra space for the purpose of space complexity analysis.)*/

class Solution {
public:
    
    
    //Approach 1: fails for I/P: [1,0], O/P: [0,0], Expected: [0,1]
    /*vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> out;
        out.resize(n);
        int p=1;
        for(int i=0;i<n;i++)
        {
            p*=nums[i];
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]!=0)
            out[i]=p*pow(nums[i],-1);
        }
        return out;
    }*/
    
    //Approach 2: O(n) time and O(n) space
    /*vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> L;
        L.resize(n);
        vector<int> R;
        R.resize(n);
        
        //L[i] stores the product of all elements to the left of ith index in nums
        L[0]=1;
        for(int i=1;i<n;i++)
        {
            L[i]=L[i-1]*nums[i-1];
        }
        
        //R[i] stores the product of all elements to the right of ith index in nums
        R[n-1]=1;
        for(int i=n-2;i>=0;i--)
        {
            R[i]=R[i+1]*nums[i+1];
        }
        
        //out[i] stores the product of all elements except nums[i]
        vector<int> out;
        out.resize(n);
        for(int i=0;i<n;i++)
        {
            out[i]=L[i]*R[i];
        }
        return out;
    }*/
    
    
    //Approach 3: O(n) time and O(1) space
    vector<int> productExceptSelf(vector<int>& nums) {
        int n=nums.size();
        vector<int> ans;
        ans.resize(n);
        
        //for time being ans[i] stores the product of all elements to the left of ith index in nums
        ans[0]=1;
        for(int i=1;i<n;i++)
        {
            ans[i]=ans[i-1]*nums[i-1];
        }
    
        //r stores the product to the right of ith index and is updated every time in the loop along with the value of i
        //now ans stores the desired output
        int r=1;
        for(int i=n-1;i>=0;i--)
        {
            ans[i]*=r;
            r*=nums[i];
        }
        return ans;
    }
    
    //Approach 4: Using properties of Log. Fails when array also has 0 in it
    /*vector<int> productExceptSelf(vector<int>& nums)
    {
        int n=nums.size();
        vector<int> out;
        out.resize(n);
        long double sum=0;
        //taking log of each element and adding to the sum
        for(int i=0;i<n;i++)
        {
            sum+=(long double)log10(nums[i]);
        }
        
        //sub log(nums[i]) and taking antilog
        for(int i=0;i<n;i++)
        {
            out[i]=(int)(pow(10.0000,sum-(long double)log10(nums[i])));
        }
        return out;
        
    }*/
};