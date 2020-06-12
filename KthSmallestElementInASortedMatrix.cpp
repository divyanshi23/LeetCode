/*Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.

Note that it is the kth smallest element in the sorted order, not the kth distinct element.

Example:

matrix = [
   [ 1,  5,  9],
   [10, 11, 13],
   [12, 13, 15]
],
k = 8,

return 13.
Note:
You may assume k is always valid, 1 ≤ k ≤ n2.*/

class Solution {
public:
    
    
    //Approach 1: Using priority queue
    /*int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int** visited=new int*[n];
        for(int i=0;i<n;i++)
        {
            visited[i]=new int[n]();
        }
        //min heap to store the elements and thier indices 
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;
        int i=0,j=0;
        pq.push(make_pair(matrix[0][0],make_pair(0,0)));
        visited[0][0]=1;
        k--;
        while(k)
        {
            pair<int,pair<int,int>> temp=pq.top();
            pq.pop();
            int i=temp.second.first;
            int j=temp.second.second;
            if(i+1<n && !visited[i+1][j])
            {
                pq.push(make_pair(matrix[i+1][j],make_pair(i+1,j)));
                visited[i+1][j]=1;
            }
            if(j+1<n && !visited[i][j+1])
            {
                pq.push(make_pair(matrix[i][j+1],make_pair(i,j+1)));
                visited[i][j+1]=1;
            }
            k--;
        }
        return pq.top().first;
    }*/
    
    
    //Approach2: Using Binary Search
    //ref: https://www.youtube.com/watch?v=G5wLN4UweAM&feature=youtu.be
    
    //function to find the number of elements less than or equal to val in a sorted matrix
    //takes O(2n) time as all rows and columns are traversed just once
    int count(vector<vector<int>>& matrix, int val)
    {
        int c=0;
        int n=matrix.size();
        //start searching the matrix from the bottom left corner
        int i=n-1;
        int j=0;
        while(i>=0 && j<n)
        {
            if(matrix[i][j]<=val)
            {
                //all elements in the jth column till ith row are less than val
                //inc c by i+1
                c+=(i+1);
                //move to the next column
                j++;
            }
            else
            {
                //no contribution from matrix[i][j] to c
                //dec row by 1
                i--;
            }
        }
        
        return c;
    }
    
    //takes O(log(maxVal)*2n)
    //log(maxVal) becoz of binary search and 2n becoz of calling count func
    int kthSmallest(vector<vector<int>>& matrix, int k)
    {
        int n=matrix.size();
        int high=matrix[n-1][n-1];     //max element in the matrix
        int low=matrix[0][0];       //min element in the matrix
        //our kth smallest element lies in the search space low to high
        int ans;
        while(low<=high)
        {
            int mid=low+(high-low)/2;
            int num=count(matrix,mid);  //number of elements less than or equal to mid
            if(k<=num)
            {
                //store mid as ans and search on the left part for kth smallest element
                ans=mid;
                high=mid-1;
            }
            else
            {
                //search on the right side
                low=mid+1;
            }
        }
        return ans;
    }
};