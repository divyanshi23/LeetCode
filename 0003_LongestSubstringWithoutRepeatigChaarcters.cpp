/*Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3 
Explanation: The answer is "abc", with the length of 3. 
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. 
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.*/


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        int i=0,j=0,maxLen=0;
        unordered_map<char,int> map;
        while(i<n && j<n)
        {
            if(map.count(s[j])==0)
            {
                map[s[j]]=j;
                j++;
                maxLen=max(maxLen,j-i);
            }
            else
            {
                //map.clear();
                //j++;
                i=map[s[j]]+1;
                map[s[j]]=j;
                j++;
                
                /*map.erase(s[i]);
                i++;*/
            }
        }
        return maxLen;
    }
};