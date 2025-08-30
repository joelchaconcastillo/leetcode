class Solution {
public:
    int m, n;
    unordered_set<int> ones;
    Solution(int m, int n):m(m), n(n) {
        
    }
    
    vector<int> flip() {
	    int picked = rand()%(m*n);
	    while(ones.count(picked)>0) picked = rand()%(m*n);
	    ones.insert(picked);
	    return {picked/n, picked%m};
    }
    
    void reset() {
	    ones.clear();
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(m, n);
 * vector<int> param_1 = obj->flip();
 * obj->reset();
 */
