/*Given two sorted integer arrays nums1 and nums2, merge nums2 into nums1 as one sorted array.

Note:

The number of elements initialized in nums1 and nums2 are m and n respectively.
You may assume that nums1 has enough space (size that is greater or equal to m + n) to hold additional elements from nums2.*/

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        //auto it1=nums1.begin();
        //auto it2=nums2.begin();
        int i=m-1;int j=n-1;
        int ind=m+n-1;
        while(i>=0&&j>=0)
        {
            if(nums1[i]>nums2[j])
            {
                nums1[ind]=nums1[i];
                //nums1.insert(nums1.begin()+ind,nums2[j]);
                i--;
            }
            else
            {
                nums1[ind]=nums2[j];
                j--;
            }
            ind--;
            //i++;
        }
        while(i>=0)
        {
            nums1[ind]=nums1[i];
            i--;
            ind--;
        }
        while(j>=0)
        {
            nums1[ind]=nums2[j];
            //nums1.insert(nums1.begin()+ind,nums2[j]);
            j--;
            ind--;
        }
        /*
        for(int i=0;i<n;i++)
        {
            nums1.pop_back();
        }*/
    }
};