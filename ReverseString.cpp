/*Write a function that reverses a string. The input string is given as an array of characters char[].

Do not allocate extra space for another array, you must do this by modifying the input array in-place with O(1) extra memory.

You may assume all the characters consist of printable ascii characters.*/

class Solution {
public:
    void reverseString(vector<char>& s) {
        int l=0;
        int r=s.size()-1;
        char temp;
        while(l<r)
        {
            temp=s[l];
            s[l]=s[r];
            s[r]=temp;
            l++;r--;
        }
    }
};