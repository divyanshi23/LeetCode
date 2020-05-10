/*Given a non-negative integer numRows, generate the first numRows of Pascal's triangle.

Example:

Input: 5
Output:
[
     [1],
    [1,1],
   [1,2,1],
  [1,3,3,1],
 [1,4,6,4,1]
]*/

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> ans;
        
        if(numRows==0)
            return ans;
        
        vector<int> v1;
        v1.push_back(1);
        ans.push_back(v1);
        if(numRows==1)
        {
            return ans;
        }
        
        vector<int> v2;
        v2.push_back(1);
        v2.push_back(1);
        ans.push_back(v2);
        if(numRows==2)
        {
            return ans;
        }
        
        for(int i=2;i<numRows;i++)
        {
            vector<int> v;
            v.push_back(1);
            for(int j=1;j<ans[i-1].size();j++)
            {
                v.push_back(ans[i-1][j-1]+ans[i-1][j]);
            }
            v.push_back(1);
            ans.push_back(v);
        }
        return ans;
    }
};