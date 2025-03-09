class Solution {
public:
    /*
         time: O(n*k)
         space: O(n)
	 elapses time to solve: 9 min. (edge case tricky)
     * */ 
    int solve(vector<int> &nums, int k){
        int n = nums.size();
	unordered_map<int, int> counter;
	for(int i = 0 ; i+k <= n; i++){// 0 0
	   unordered_set<int> marked;
	   for(int j = i; j<i+k; j++){
	      marked.insert(nums[j]);
	   }
	   for(auto ii:marked)counter[ii]++;
	}
	int res = -1;
	for(auto ii:counter){
	   if(ii.second!=1)continue;
	   res = max(res, ii.first);
	}
	return res;
    }
    int largestInteger(vector<int>& nums, int k) {
	return solve(nums, k);
    }
};
