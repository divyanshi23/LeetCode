/*Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.



Example:

Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:

Although the above answer is in lexicographical order, your answer could be in any order you want.*/

class Solution {
public:
    
    string map[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    
    vector<string> letterCombinationsHelper(string digits) {
        vector<string> ans;
        //base case
        if(digits=="")
        {   ans.push_back("");
            return ans;
        }
        
        //rec call
        vector<string> temp=letterCombinationsHelper(digits.substr(1,digits.size()-1));
        
        //self calc
        string s=map[digits[0]-'0'];
        for(char i:s)
        {
            for(string j:temp)
            {
                ans.push_back(i+j);
            }
        }
        return ans;
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        //base case
        if(digits=="")
        {   //ans.push_back("");
            return ans;
        }
        
        return letterCombinationsHelper(digits);
    }
};