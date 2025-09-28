class Solution {
public:
    unordered_map<int, int> memo;
    int dfs(vector<int> &nums, int idx, unordered_set<int> &marked){
	    if(marked.count(idx))return 0;
	    marked.insert(idx);
	    if(memo.count(idx))return memo[idx];
	    return memo[idx] = dfs(nums, nums[idx], marked)+1;
    }
    int solve1(vector<int>& nums) {
	    int res = 0, n = nums.size();
	    unordered_set<int> marked;
	    for(int i = 0 ; i <n; i++){
		    res = max(res, dfs(nums, i, marked));
	    }
	    return res;
    }
    int solve2(vector<int> &nums){
	    int n = nums.size(), res = 0;
	    unordered_set<int> marked;
	    for(int i = 0 ;i < n; i++){
		    int j = i, len=0;
		    while(!marked.count(j)){
			    marked.insert(j);
			    j = nums[j];
			    len++;
		    }
		    res = max(res, len);
	    }
	    return res;
    }
    int arrayNesting(vector<int>& nums) {
	    return solve2(nums);
    }
};
