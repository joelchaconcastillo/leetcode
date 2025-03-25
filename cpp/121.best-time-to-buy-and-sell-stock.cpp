class Solution {
public:
    // time: O(n)
    // space O(1)
    // elapsed time to solve: 2 min.
    int solve(vector<int> &prices){
	int minv=INT_MAX, maxv=INT_MIN;
	int res = 0;
	for(auto i:prices){
	   minv = min(minv, i);
	   res = max(res, max(0, i-minv));
	}
	return res;
    }
    int maxProfit(vector<int>& prices) {
	   return solve(prices);
    }
};
