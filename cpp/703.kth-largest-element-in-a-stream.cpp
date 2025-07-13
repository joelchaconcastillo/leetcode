class KthLargest {
public:
    multiset<int> data;
    int k;
    KthLargest(int k, vector<int>& nums) {
        for(auto i:nums)data.insert(i);
	this->k = k;
    }
    
    int add(int val) {
	    data.insert(val);
	    while( data.size() > k){
		    data.erase(data.begin());
	    }
	    return *data.begin();
    }
};

/**
 * Your KthLargest object will be instantiated and called as such:
 * KthLargest* obj = new KthLargest(k, nums);
 * int param_1 = obj->add(val);
 */
