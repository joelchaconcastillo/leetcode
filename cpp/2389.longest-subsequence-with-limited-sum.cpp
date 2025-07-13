class Solution {
public:
    vector<int> solve(vector<int> &nums, vector<int> &queries){
	    vector<int> res;
	    int n = nums.size();
	    sort(nums.begin(), nums.end());
	    vector<int> pref(n,0);
	    pref[0]=nums[0];
	    for(int i = 1 ; i < n; i++){
		    pref[i] = pref[i-1]+nums[i];
	    }
	    for(auto limit:queries){
		    int len = upper_bound(pref.begin(), pref.end(), limit)-pref.begin();
		    res.push_back(len);
	    }
	    return res;
    }
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
	    return solve(nums, queries);
    }
};
/*
 Your input:    [4,5,2,1]↩ [3,10,21]↩ [2,3,4,5]↩ [1]
                 1 3 7 5
                   *
Output:        [1,3,4]↩ [0]↩ 
Expected:      [2,3,4]↩ [0]
 * */
