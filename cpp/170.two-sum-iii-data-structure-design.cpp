class TwoSum {
	vector<long long> nums;
	unordered_map<long long, int> freq;
public:
    TwoSum() {
        
    }
    
    void add(int number) {
	    nums.push_back(number);
	    freq[number]++;
    }
    
    bool find(int value) {
	    for(auto [num1, cont]:freq){
		    int num2 = value-num1;
		    if(num2 == num1 && cont >= 2)return true;
		    if(num1 != num2 && freq.count(num2))return true;
	    }
		    return false;
    }
};

/**
 * Your TwoSum object will be instantiated and called as such:
 * TwoSum* obj = new TwoSum();
 * obj->add(number);
 * bool param_2 = obj->find(value);
 */
