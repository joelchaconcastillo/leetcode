class Solution {
public:
    unordered_map<int, unordered_map<int, int> >memo;
    int helper(int l, int r){
	    if(l+1>=r)return 0;
	    if(memo.count(l) && memo[l].count(r))return memo[l][r];
	    int res = INT_MAX;
	    for(int i = l; i < r; i++){
		    auto current = max(helper(l,i), helper(i+1, r))+i;
		    res = min(current, res);
	    }
	    return memo[l][r] = res;
    }
    int getMoneyAmount(int n) {
       	   return helper(1, n+1); 
    }
};
