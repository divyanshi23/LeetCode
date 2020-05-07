/*Given a non-empty array of digits representing a non-negative integer, plus one to the integer.

The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.

You may assume the integer does not contain any leading zero, except the number 0 itself.

Example 1:

Input: [1,2,3]
Output: [1,2,4]
Explanation: The array represents the integer 123.*/

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size();
        if(n==1 && digits[n-1]==9)
        {
            digits.pop_back();
            digits.push_back(1);
            digits.push_back(0);
            return digits;
        }
        if(digits[n-1]!=9)
        {
            digits[n-1]++;
        }
        else
        {
            digits.pop_back();
            digits=plusOne(digits);
            digits.push_back(0);
        }
        return digits;
    }
};