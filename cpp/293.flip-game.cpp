class Solution {
public:
    void dfs(string &st, int i, vector<string> &res){
	    if(i==st.size()){
		    res.push_back(st);
		    return;
	    }
	    if(i+1<st.size() && st[i]=='+' && st[i+1]=='+'){
		    st[i]='-';
		    st[i+1] = '-';
		    dfs(st, i+1, res);
		    st[i]='+';
		    st[i+1] = '+';
	    }
	    dfs(st, i+1, res);
    }
    vector<string> solve(string &st){
	    vector<string> res;
	    for(int i = 0 ; i+1<st.size(); i++){
		    if(st[i]!='+' || st[i+1] !='+')continue;
		    auto copy = st;
		    copy[i]='-';
		    copy[i+1]='-';
		    res.push_back(copy);
	    }
	    return res;
    }// +++++--
    vector<string> generatePossibleNextMoves(string currentState) {
	    return solve(currentState);
    }
};
