class MyHashMap {
public:
    int BucketSize=1000;
    vector<vector<pair<int, int> > > data;
    MyHashMap() {
	    data.assign(BucketSize, vector<pair<int, int>>());
    }
    
    void put(int key, int value) {
	    for(int i = 0 ; i < data[key%BucketSize].size(); i++){
		    if(data[key%BucketSize][i].first == key){
			    data[key%BucketSize][i].second=value;
			    return;
		    }
	    }
	    data[key%BucketSize].push_back({key, value});
    }
    
    int get(int key) {
        for(auto [_key, _val] :data[key%BucketSize]){
		if(_key == key)return _val;
	}
	return -1;
    }
    
    void remove(int key) {
	    for(int i = 0 ; i < data[key%BucketSize].size(); i++){
		    if(data[key%BucketSize][i].first == key){
			    data[key%BucketSize].erase(data[key%BucketSize].begin()+i);
			    break;
		    }
	    }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */
