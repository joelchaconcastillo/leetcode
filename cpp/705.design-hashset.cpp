class MyHashSet {
public:
    vector<unordered_set<int> > exists;
    const int Bucket = 100;
    MyHashSet() {
       exists.assign(Bucket, {}); 
    }
    
    void add(int key) {
	    exists[key%Bucket].insert(key);
    }
    
    void remove(int key) {
	    exists[key%Bucket].erase(key);
    }
    
    bool contains(int key) {
	    return exists[key%Bucket].count(key);
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */
