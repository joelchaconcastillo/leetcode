class Solution {
public:
    long long solve(string &st, int k){
	    unordered_map<char, int>f;
	    long long res = 0;
	    int l = 0, n = st.size();
	    for(int i = 0 ; i < n; i++){
		    f[st[i]]++;
		    while( l <= i && f[st[i]] >=k){
			    res += n-i;
			    f[st[l++]]--;
		    }

	    }
	    return res;
    }
    long long numberOfSubstrings(string s, int k) {
	    return solve(s, k);
    }
};
