class Solution {
public:
    int solve(vector<int>& arr) {
	    unordered_map<int, int>freq;
	    for(auto num:arr)freq[num]++;
	    int res = 0;
	    for(auto [val, cont]:freq){
		  if(freq.count(val+1)) res+=cont;
	    }
	    return res;
    }
    int countElements(vector<int>& arr) {
	return solve(arr);
    }
};
