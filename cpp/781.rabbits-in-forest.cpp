class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> freq;
        for(auto ans:answers) freq[ans]++;
	int res= 0 ;
	for(auto [val, cont]:freq){
		res += ceil(cont/(val+1.0))*(val+1);
	}
        return res;
    }
};
