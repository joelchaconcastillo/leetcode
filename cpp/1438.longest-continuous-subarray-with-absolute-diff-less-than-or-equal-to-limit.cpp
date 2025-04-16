class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        set<pair<int, int> > window;
	int l = 0, n = nums.size(), res = 0;
	for(int i = 0 ;i < n; i++){
	   window.insert({nums[i], i});
	   while(!window.empty() && 
			   prev(window.end())->first - window.begin()->first > limit){
	    window.erase({nums[l], l});
	    l++;
	   }
	   res = max(res, i-l+1);
	}
	return res;
    }
};
/*
 
               i
	   l

set<pair<int, int>> window;

 * */
