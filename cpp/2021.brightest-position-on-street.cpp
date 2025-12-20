class Solution {
public:
    int solve(vector<vector<int>>& lights) {
	    int n = lights.size();
	    map<long long, int> freq;
	    for(auto &light:lights){
		    freq[light[0]-light[1]]++;
		    freq[light[0]+light[1]+1]--;
	    }
	    long long current = 0, res = 0, start = INT_MAX;
	    for(auto &[key, val]:freq){
		    current +=val;
		    if(current > res){
			    current = res;
			    start = key;
		    }else if(current == res){
			    start = min(start, key);
		    }
	    }
	    return start;
    }
    int brightestPosition(vector<vector<int>>& lights) {
	    return solve(lights);
    }
};
