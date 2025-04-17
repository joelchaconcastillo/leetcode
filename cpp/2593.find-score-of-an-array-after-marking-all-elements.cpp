class Solution {
public:
    long long solve(vector<int> &nums){
	int n = nums.size();
	priority_queue<pair<long long, int> > pq;
	for(int i = 0 ; i< n; i++) pq.push({-nums[i], -i});
	vector<bool>marked(n, false);
	long long res = 0;
	while(!pq.empty()){
	    auto current_pp = pq.top(); pq.pop();
	    if(marked[-current_pp.second])continue;
	    res += -current_pp.first;
	    marked[-current_pp.second]=true;
	    marked[max(0, -current_pp.second-1)]=true;
	    marked[min(n-1, -current_pp.second+1)]=true;
	}
	return res;
    }
    long long findScore(vector<int>& nums) {
	    return solve(nums);
    }
};
