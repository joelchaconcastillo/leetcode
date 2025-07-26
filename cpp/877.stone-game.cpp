class Solution {
public:
    int helper(vector<int> &piles, int l, int r, vector<vector<int>> &memo){
	    if(l==r){
		    return 0;
	    }
	    if(memo[l][r]!=-1)return memo[l][r];
	    int res = helper(piles, l+1, r,memo)+((r-l+1)%2==1)?0:piles[l];
	    res = max(res, helper(piles, l, r-1, memo)+((r-l+1)%2==1)?0:piles[r]);
	    return memo[l][r] = res;
    }
    bool solve(vector<int> &piles){
	    int n =piles.size();
	    vector<vector<int>>memo(n, vector<int>(n, -1));
	    return helper(piles, 0, piles.size()-1, memo);
    }
    inline bool solve2(vector<int> &piles){return true;}
    bool stoneGame(vector<int>& piles) {
	    return solve2(piles);
	    return solve(piles);
    }
};
