class Solution {
public:
    string s1,s2,s3;
    int n, m, b;
    int memo[500][500];
    bool helper(int i, int j, int k){
	    if(i+j == b){
		return true;
	    }
	    if(memo[i][j]!= -1)return memo[i][j];
	    bool res = false;
	    if(i < n && s1[i] == s3[k]){
		res |= helper(i+1, j, k+1);

	    }
	    if(j < m && s2[j] == s3[k]){
	        res |= helper(i, j+1, k+1);
	    }
	    return memo[i][j] = res;
    }
    bool solve(string &s1, string &s2, string &s3){
	    memset(memo, -1, sizeof memo);
	    this->s1 = s1;
	    this->s2 = s2;
	    this->s3 = s3;
	    n = s1.size();
	    m = s2.size();
	    b = s3.size();
	    if(n+m != b)return false;
	    return helper(0, 0, 0);
    }
    bool solve2(string s1, string s2, string s3) {
	 int n = s1.size(), m = s2.size(), p = s3.size();
	 if(n+m!=p)return false;
	 vector<vector<bool> > dp(n+1, vector<bool> (m+1, false));
	 dp[0][0] = true;
	 for(int i = 1; i <=n; i++) dp[i][0] = s1.substr(0,i) == s3.substr(0,i);
	 for(int j =1; j <=m; j++) dp[0][j] = s2.substr(0, j)==s3.substr(0, j);
	 for(int i = 1; i <=n; i++){
		 for(int j = 1; j<=m; j++){
			 dp[i][j] = (dp[i-1][j] && s1[i-1]==s3[i+j-1]) || (dp[i][j-1] && s2[j-1] == s3[i+j-1]);
		 }
	 }
	 return dp.back().back();
    }
    bool isInterleave(string s1, string s2, string s3) {
	    return solve2(s1, s2, s3);
	    return solve(s1, s2, s3);
    }
};
///  a ab d    
///
///    ab c
///
///  aabc
