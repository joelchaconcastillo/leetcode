class Solution {
public:
    unordered_map<int, unordered_map<int, int > > memo;
    int dfs(vector<int> &stones, int idx, int current_sum, int limit){
	    if(idx == stones.size()) return current_sum;
	    if(memo.count(idx) && memo[idx].count(current_sum))return memo[idx][current_sum];
	    int res = dfs(stones, idx+1, current_sum, limit);
	    if(stones[idx]+current_sum <= limit){
		    res = max(res, 
				    dfs(stones, idx+1, current_sum+stones[idx], limit));
	    }
	    return memo[idx][current_sum]=res;
    }
    // | A - B | -> | A - (S-A)| --> | 2A - S |
    // min_A | 2A-S |
    int lastStoneWeightII(vector<int>& stones) {
            int S = accumulate(stones.begin(), stones.end(),0);
	    int half = S/2;
	    int opt_A = dfs(stones, 0, 0, half);
	    return S - 2*opt_A;
    }
};
//   2 7 4 1 8 1
//   1 1 2 4 7 8 
//   1 1 1 2 4
//   1 1 1 2
//   1 1 1
//   1
//
//
//   [31,26,33,21,40]
//    21 26 31 33 40
//    x
