class Solution {
public:
    int solve(string &st, int k){
	    int l = 0, n = st.size(), res = 0;
	    unordered_set<char> visited;
	    for(int i = 0 ; i < n ;i++){
		    while(l < i && (visited.count(st[i]) || visited.size()>=k) ){
			    visited.erase(st[l]);
			    l++;
		    }
		    visited.insert(st[i]);
		    if(visited.size()==k)res++;
	    }
	    return res;
    }
    int numKLenSubstrNoRepeats(string s, int k) {
	    return solve(s, k);
    }
};
