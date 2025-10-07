class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        vector<pair<int, int>>tmp;
	int n = nums.size();
	for(int i=0; i<n; i++){
		tmp.push_back({nums[i], i});
	}
	sort(tmp.begin(), tmp.end());
	int maxv=-1, res=0;
	for(int i=n-1; i>=0; i--){
		res = max({res, maxv-tmp[i].second});  
		maxv = max(maxv, tmp[i].second);
	}
	return res;
    }
};
// 0 1 2 3 4 5
//[6,0,8,2,1,5]
// 0,1 1,4 2,3 5,5 6,0 8,2
