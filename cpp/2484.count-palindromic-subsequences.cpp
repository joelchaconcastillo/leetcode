class Solution {
public:

    int solve(string &st){
	    int n = st.size(), MOD = 1e9+7;
	    vector<string> patterns;
	    for(int i = 0; i < 10; i++){
		    for(int j = 0; j < 10; j++){
			    string pattern = "";
			    pattern = (i+'0');
			    pattern += (j+'0');
			    pattern +=(0+'0');
			    pattern +=(j+'0');
			    pattern +=(i+'0');
			    patterns.push_back(pattern);
		    }
	    }
	    long long res=0;
	    for(auto &pattern: patterns){
	       vector<long long> dp(6, 0);//dp(i) is the number of times a sufix matches
	       dp.back()=1;
	       for(int i = 0 ; i < n ;i++){
		    for(int j = 0; j < 5; j++){
			    if( st[i] == pattern[j] || j==2) dp[j] = (dp[j]+dp[j+1])%MOD;
		    }
	       }
	       res = (res+dp[0])%MOD;
	    }
	    return res;
    }
    int countPalindromes(string s) {
	    return solve(s);
    }
};
