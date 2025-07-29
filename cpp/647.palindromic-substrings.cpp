class Solution {
public:
    int solve2(string &st){
	    int n = st.size();
	    vector<vector<int> > dp(n, vector<int> (n, 0));
	    for(int i = 0 ; i < n; i++) dp[i][i]=1;
	    for(int i = 0; i+1<n; i++) dp[i][i+1] = (st[i]==st[i+1]);
	    for(int l = 3; l <= n; l++){
		    for(int i=0,j=i+l-1; j < n; j++, i++){
			    dp[i][j] = (st[i] == st[j]) && dp[i+1][j-1];
		    }
	    }
	    int res = 0;
	    for(int i = 0 ;i  <n; i++){
		    res += accumulate(dp[i].begin(), dp[i].end(), 0);
	    }
	    return res;
    }
    int solve(string &st){
	    int n = st.size(), res = 0 ;
	    vector<vector<int> > dp(n, vector<int> (n,0));
	    for(int i = 0 ;i  < n ; i++){
		    int l=i,r=i;
		    while(l>=0 && r<n && st[l]==st[r]){
			    res++;
			 l--,r++;
		    }
		    l=i, r=i+1;
		    while(l>=0 && r<n && st[l]==st[r]){
			    res++;
			 l--,r++;
		    }
	    }
	    return res;
    }
    int countSubstrings(string s) {
	    return solve2(s);
	    return solve(s);
    }
};
