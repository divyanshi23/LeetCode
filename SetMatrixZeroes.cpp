/*Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in-place.

Example 1:

Input: 
[
  [1,1,1],
  [1,0,1],
  [1,1,1]
]
Output: 
[
  [1,0,1],
  [0,0,0],
  [1,0,1]
]
Example 2:

Input: 
[
  [0,1,2,0],
  [3,4,5,2],
  [1,3,1,5]
]
Output: 
[
  [0,0,0,0],
  [0,4,5,0],
  [0,3,1,0]
]
Follow up:

A straight forward solution using O(mn) space is probably a bad idea.
A simple improvement uses O(m + n) space, but still not the best solution.
Could you devise a constant space solution?*/

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r=matrix.size();
        int c=matrix[0].size();
        
        int r0=0,c0=0;
        /*if(matrix[0][0]==0)
            f=1;*/
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                    if(i==0)
                        r0=1;
                    if(j==0)
                        c0=1;
                }
            }
        }
        
        
        for(int i=1;i<r;i++)
        {
            if(matrix[i][0]==0)
            {
                for(int j=0;j<c;j++)
                {
                    matrix[i][j]=0;
                }
            }
        }
        
        for(int i=1;i<c;i++)
        {
            if(matrix[0][i]==0)
            {
                for(int j=0;j<r;j++)
                {
                    matrix[j][i]=0;
                }
            }
        }
        
        if(c0)
        {
            for(int i=0;i<r;i++)
            {
                matrix[i][0]=0;
            }
        }
        if(r0)
        {
            for(int i=0;i<c;i++)
            {
                matrix[0][i]=0;
            }
        }
    }
};