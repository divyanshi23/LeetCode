/*Design and implement a data structure for Least Recently Used (LRU) cache. It should support the following operations: get and put.

get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
put(key, value) - Set or insert the value if the key is not already present. When the cache reached its capacity, it should invalidate the least recently used item before inserting a new item.

The cache is initialized with a positive capacity.

Follow up:
Could you do both operations in O(1) time complexity?

Example:

LRUCache cache = new LRUCache( 2 ); // capacity 

cache.put(1, 1);
cache.put(2, 2);
cache.get(1);       // returns 1
cache.put(3, 3);    // evicts key 2
cache.get(2);       // returns -1 (not found)
cache.put(4, 4);    // evicts key 1
cache.get(1);       // returns -1 (not found)
cache.get(3);       // returns 3
cache.get(4);       // returns 4*/

class LRUCache {
    
    list<pair<int,int>> dq;
    unordered_map<int,list<pair<int,int>>::iterator> m;
    int c;
    
public:
    LRUCache(int capacity) {
        c=capacity;
    }
    
    int get(int key) {
        
        //Page exists in cache
        if(m.find(key)!=m.end())
        {
            auto ptr=m.find(key)->second;
            int v=ptr->second;
            dq.erase(m[key]);
            dq.push_front(make_pair(key,v));
            m[key]=dq.begin();
            return v;
        }
        //page does not exist in cache              
        else
            return -1;
    }
    
    void put(int key, int value) {
        
        //key value pair already exists so just update it
        if(m.find(key)!=m.end())
        {
            auto ptr=m.find(key)->second;
            //int v=ptr->second;
            dq.erase(m[key]);
            dq.push_front(make_pair(key,value));
            m[key]=dq.begin();
        }
        
        //make a new entry in cache
        else
        {
            //there is space in cache so just add the new key value pair
            if(dq.size()!=c)
            {
                dq.push_front(make_pair(key,value));
                m[key]=dq.begin();
            }
            
            //cache is full so need to remove the least recently used pair and then add
            else
            {
                auto last=dq.back();
                dq.pop_back();
                m.erase(last.first);
                dq.push_front(make_pair(key,value));
                m[key]=dq.begin();
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */