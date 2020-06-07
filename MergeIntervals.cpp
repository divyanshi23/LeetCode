/*Given a collection of intervals, merge all overlapping intervals.

Example 1:

Input: [[1,3],[2,6],[8,10],[15,18]]
Output: [[1,6],[8,10],[15,18]]
Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
Example 2:

Input: [[1,4],[4,5]]
Output: [[1,5]]
Explanation: Intervals [1,4] and [4,5] are considered overlapping.*/

bool comp(vector<int> v1,vector<int> v2)
{
    return (v1[0]<v2[0]);
}


class Solution {
public:
    
    
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> v;
        int n=intervals.size();
        if(n==0)
            return v;
        /*sort(intervals.begin(),intervals.end(),comp);
        int s=0,e=0;
        while(s<n)
        {
            vector<int> temp;
            temp.push_back(intervals[s][0]);
            while(s<n-1 && intervals[s][1]>=intervals[s+1][0])
            {
                e++;
                s++;
            }
            temp.push_back(intervals[e][1]);
            v.push_back(temp);
            s++;
            e++;
        }
        return v;*/
        sort(intervals.begin(),intervals.end(),comp);
        int i=0;
        int e=INT_MIN;
        while(i<n)
        {
            e=intervals[i][1];
            vector<int>temp;
            temp.push_back(intervals[i][0]);
            while(i<n-1 && intervals[i+1][0]<=e)
            {
                e=max(e,intervals[i+1][1]);
                i++;
            }
            temp.push_back(e);
            i++;
            v.push_back(temp);
        }
        return v;
        
    }
};

    