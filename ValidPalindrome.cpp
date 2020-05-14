/*Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.

Note: For the purpose of this problem, we define empty string as valid palindrome.

Example 1:

Input: "A man, a plan, a canal: Panama"
Output: true
Example 2:

Input: "race a car"
Output: false*/

class Solution {
public:
    bool isPalindrome(string s) {
        if(s==" " || s=="")
            return true;
        int l=0,r=s.size()-1;
        while(l<=r)
        {
            while(!isalnum(s[l]) && l<s.size())
            {
                l++;
            }
            while(!isalnum(s[r]) && r>0)
            {
                r--;
            }
            if(l<=r && tolower(s[l])==tolower(s[r]))
            {
                l++;r--;
            }
            else if(l<=r && tolower(s[l])!=tolower(s[r]))
            {
                return false;
            }
        }
        return true;
    }
};