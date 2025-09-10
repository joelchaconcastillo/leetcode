class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        long long minv = INT_MAX, maxv=INT_MIN;
	long long res = 0;
        for(auto &arr:arrays){
		long long val1 = arr.back()-minv;
		long long val2 = maxv-arr.front();
		res = max({res, val1, val2});
		minv = min(minv, (long long)arr.front());
		maxv = max(maxv, (long long)arr.back());
	}	
	return res;
    }
};
