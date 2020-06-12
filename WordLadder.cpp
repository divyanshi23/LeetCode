/*Given two words (beginWord and endWord), and a dictionary's word list, find the length of shortest transformation sequence from beginWord to endWord, such that:

Only one letter can be changed at a time.
Each transformed word must exist in the word list.
Note:

Return 0 if there is no such transformation sequence.
All words have the same length.
All words contain only lowercase alphabetic characters.
You may assume no duplicates in the word list.
You may assume beginWord and endWord are non-empty and are not the same.
Example 1:

Input:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]

Output: 5

Explanation: As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
return its length 5.
Example 2:

Input:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]

Output: 0

Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.*/


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //to store the list of words corresponding to possible intermediate states
        unordered_map<string,list<string>> map;    
        int n=wordList.size();
        int m=wordList[0].size();
        
        //filling the map
        for(int i=0;i<n;i++)
        {
            string s=wordList[i];
            
            //making all possible intermediate states for every word of the wordList and then populating the map 
            for(int j=0;j<m;j++)
            {
                string intermediate_state;
                if(j==0)
                    intermediate_state='*'+s.substr(j+1,m-j-1);
                else if(j==m-1)
                    intermediate_state=s.substr(0,j)+'*';
                else
                    intermediate_state=s.substr(0,j)+'*'+s.substr(j+1,m-j-1);
                if(map.count(intermediate_state)==0)
                {
                    list<string> l;
                    l.push_back(s);
                    map[intermediate_state]=l;
                }
                else
                    map[intermediate_state].push_back(s);
            }
        }
        
        //visited hashmap for tracking all the visited words to avoid cycles
        unordered_map<string,int> visited;
        for(int i=0;i<n;i++)
        {
            visited[wordList[i]]=0;
        }
        
        //BFS traversal
        //q stores the word and the level at which that word is
        queue<pair<string,int>> q;
        visited[beginWord]=1;
        q.push(make_pair(beginWord,1));
        while(!q.empty())
        {
            pair<string,int> p=q.front();
            q.pop();
            string s=p.first;
            int level=p.second;
            
            //if endWord found return its level
            if(s==endWord)
                return level;
            for(int j=0;j<m;j++)
            {
                //neighbours of a word are the words that share any intermediate state with the current word
                string intermediate_state;
                if(j==0)
                    intermediate_state='*'+s.substr(j+1,m-j-1);
                else if(j==m-1)
                    intermediate_state=s.substr(0,j)+'*';
                else
                    intermediate_state=s.substr(0,j)+'*'+s.substr(j+1,m-j-1);
                
                for(auto nbr:map[intermediate_state])
                {
                    if(!visited[nbr])
                    {
                        visited[nbr]=1;
                        //level of neighbour is 1+level of parent as it is formed by changing 1 alphabet of the word
                        q.push(make_pair(nbr,level+1));
                    }
                }
            }
        }
        
        //if endWord not found then return 0
        return 0;
    }
};