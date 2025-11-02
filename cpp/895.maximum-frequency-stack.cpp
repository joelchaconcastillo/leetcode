class FreqStack {
public:
    int max_freq = 0;
    unordered_map<int, int> freq;
    unordered_map<int, vector<int>> freq2val;
    FreqStack() {
        
    }
    
    void push(int val) {
	    freq[val]++;
	    max_freq = max(max_freq, freq[val]);
	    freq2val[freq[val]].push_back(val);
    }
    
    int pop() {
	    auto res = freq2val[max_freq].back();
	    freq2val[max_freq].pop_back();
	    freq[res]--;
	    if(freq2val[max_freq].empty())max_freq--;
	    return res;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */
