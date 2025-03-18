class Solution {
public:
    //time: O(k) where k is the size of operations
    //space: O(1)
    //elapsed time to solve it: 30 min.
    //The trick is to realize that position 0,0 will be always modified, so the answer will be the mini row and col found at ops
    int solve(int m, int n, vector<vector<int> >&ops){
	int minR = m, minC=n;
	for(auto r_c:ops){
	   minR = min(minR, r_c[0]);
	   minC = min(minC, r_c[1]);
	}
	return minR*minC;
    }
    int maxCount(int m, int n, vector<vector<int>>& ops) {
      return solve(m, n, ops);    
    }
};
