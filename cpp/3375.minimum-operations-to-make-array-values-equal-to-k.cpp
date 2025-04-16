class Solution {
public:
    int solve(vector<int> &nums, int k){
    set<int> pq;
    for (auto i : nums) pq.insert(i);
    if( *pq.begin() < k) return -1;
    int res = 0;
    while (!pq.empty() && *prev(pq.end()) > k) {
        pq.erase(prev(pq.end())); 
        res++;
    }
    return res;
    }
    int minOperations(vector<int>& nums, int k) {
	return solve(nums, k);
    }
};
