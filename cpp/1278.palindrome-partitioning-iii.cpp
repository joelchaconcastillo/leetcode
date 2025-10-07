class Solution {
public:
    unordered_map<int, unordered_map<int, int> > memo;
    int dfs(string &st, int id, int k, vector<vector<int>> &costs){
	    if(k<0)return INT_MAX/2;
	    if(id==st.size()){
		    if(k > 0)return INT_MAX/2;
		    return 0;
	    }
	    if(memo.count(id) && memo[id].count(k))
		    return memo[id][k];
	    int res = INT_MAX/2;
	    for(int i = id; i < st.size(); i++){
		    res = min(
				    res, 
				    dfs(st, i+1, k-1, costs)+
				    costs[id][i]);
	    }
	    return memo[id][k] = res;
    }
    int min_palindrome(string st){ ///check min op to make it palindrome
        int i = 0, j = st.size()-1;
	int res =0 ;
	while(i < j){
		res += st[i++]!=st[j--];
	}
	return res;
    }
    int palindromePartition(string s, int k) {
	    int n = s.size();
	    vector<vector<int> > costs(n, vector<int> (n, 0));
	    for(int i = 0 ; i < n; i++){
		    string current = "";
		    for(int j = i; j < n; j++){
			    costs[i][j] = min_palindrome(s.substr(i, j-i+1));
		    }
	    }
	    return dfs(s, 0, k, costs);
    }
};
// dfs(i, k) = 
//               ming cost(pal, )+dfs(i+1, k-1),
//                     dfs(i+1, k)
