class LRUCache {
private: 
    list<pair<int,int>> dll; 
    unordered_map<int, list<pair<int,int>>::iterator> cache; 
    int cap; 
public:
    LRUCache(int capacity) : cap(capacity){}
    
    int get(int key) {
        auto it1 = cache.find(key); 
        if (it1 != cache.end()) {
            auto it2 = it1->second; 
            dll.splice(dll.begin(), dll, it2);
            /*
            pair<int,int> p = {it2->first, it2->second}
            dll.erase(it1->second); 
            dll.push_front(p); 
            cache[p.first] = dll.begin();
            return p.second;  
            ^ erase then reinsert
            */
            return it2->second; 
        }
        return -1; 
    }
    
    void put(int key, int value) {
        auto it = cache.find(key); 
        if (it != cache.end()) {
            dll.erase(it->second);  
        }
        dll.push_front({key, value});
        cache[key] = dll.begin();

        if (dll.size() > cap) {
            evict(); 
        }
    }

    void evict() {
        int lrukey = dll.back().first; 
        dll.pop_back(); 
        cache.erase(lrukey); 
    }
};
