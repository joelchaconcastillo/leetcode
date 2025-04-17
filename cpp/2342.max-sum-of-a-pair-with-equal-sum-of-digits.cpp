class Solution {
public:
    int solve(vector<int> &nums){
	unordered_map<int, priority_queue<int>> hash_pq;
	for(auto i:nums){
	   int sum = 0, j = i;
	   
	   while(i){
	       sum += i%10;
	       i/=10;
	   }
	   hash_pq[sum].push(j);
	}
	int res = -1;
	for(auto &ii:hash_pq){
	    if(ii.second.size() < 2) continue;
	    int current = ii.second.top();
	    ii.second.pop();
	    current+=ii.second.top();
	    res = max(res, current);
	}
	return res;
    }
    int maximumSum(vector<int>& nums) {
	return solve(nums);
    }
};
