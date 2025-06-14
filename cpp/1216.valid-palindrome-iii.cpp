class Solution {
public:
    int memo[1001][1001];
    int dfs(string &st, int i, int j){
	    if(i==j)return 1;
	    if(i+1==j) return max(2*(st[i]==st[j]), 1);
	    if(memo[i][j]!=-1)return memo[i][j];
	    int res = 0;
	    if(st[i] == st[j]) res = dfs(st, i+1, j-1)+2;
	    res = max(res, dfs(st, i+1, j));
	    res = max(res, dfs(st, i, j-1));
	    return memo[i][j] = res;
    }
    bool solve(string &st, int k){
	 memset(memo, -1, sizeof memo);
	 int n = st.size();
	 int longest = dfs(st, 0, st.size()-1);
	 return longest>=n-k;
    }
    bool isValidPalindrome(string s, int k) {
	    return solve(s, k);
    }
};
