class LRUCache {
    int capacity;
public:
    std::list<int> lru; //<key>
    std::unordered_map<int, std::pair<int, std::list<int>::iterator>> cache;// key, val, iterator to lru
    LRUCache(int capacity):capacity(capacity) {
    }
    void move_to_front(int key){
	lru.erase(cache[key].second);
	lru.push_front(key);
	cache[key].second = lru.begin();
    } 
    int get(int key) {
	if(!cache.count(key))return -1;
	move_to_front(key);
	return cache[key].first;
    }
    
    void put(int key, int value) {
	 if(cache.count(key)){
	    move_to_front(key);
	    cache[key].first = value;
	    return;
	 }
	 //it doesn't exists
	 lru.push_front(key);
	 cache[key] = {value, lru.begin()};
	 if(cache.size() > capacity){
	     int key_to_remove = lru.back();
	     lru.pop_back();
	     cache.erase(key_to_remove);
	 }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
