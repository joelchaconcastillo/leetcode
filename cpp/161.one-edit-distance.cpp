class Solution {
public:
    bool solve(string &st, string &t){
	    int n = st.size(), m = t.size();
	    vector<vector<int > > dp(n+1, vector<int> (m+1, INT_MAX));
	    for(int i = 0 ; i <= n; i++) dp[i][0] = i;
	    for(int j = 0; j <= m; j++) dp[0][j] = j;
	    for(int i = 1; i <=n; i++){
		    for(int j = 1; j<=m; j++){
			    dp[i][j] = min(dp[i-1][j], dp[i][j-1])+1;
			    if(st[i-1] != t[j-1]){
				    dp[i][j] = min(dp[i][j], dp[i-1][j-1]+1);
			    }
			    else dp[i][j] = min(dp[i][j], dp[i-1][j-1]);

		    }
	    }
	    return dp.back().back()==1;
    }
    bool solve2(string &st, string &t){
	    st = " "+st+" ";
	    t = " "+t+" ";
	    // st = " a"
	    // t  = " "
	    int n1 = st.size(), n2 = t.size();
	    if(abs(n2-n1)>1)return false;
	    for(int i = 0 ; i < min(n1, n2); i++){
		    if( st[i] != t[i]){
			  //remove it
			  if(st.substr(i+1) == t.substr(i))return true;
			  //add it 
			  else if(st.substr(i) == t.substr(i+1))return true;
			  //replace it
			  else if(st.substr(i+1) == t.substr(i+1))return true;
			  else return false;
		    }
	    }
	    return false;
    }
    bool isOneEditDistance(string s, string t) {
	    return solve2(s, t);
	    return solve(s, t);
    }
};
