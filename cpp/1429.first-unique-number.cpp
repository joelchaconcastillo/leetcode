class FirstUnique {
public:
    unordered_map<int ,int> freq;
    deque<int> q_single, q_multiple;
    FirstUnique(vector<int>& nums) {
	    for(auto i:nums){
		    add(i);
	    }
    }
    
    int showFirstUnique() {
	    while(!q_single.empty() && freq[q_single.front()] > 1){
		    q_single.pop_front();
	    }
	    if(q_single.empty())return -1;
	    return q_single.front();
    }

    void add(int value) {
	    freq[value]++;
	    if(freq[value] > 1){
		    q_multiple.push_back(value);
	    }else q_single.push_back(value);
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */
