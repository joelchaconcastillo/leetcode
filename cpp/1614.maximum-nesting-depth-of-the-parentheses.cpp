class Solution {
public:
    int solve(string &st){
	    int cnt = 0, res=0;
	    for(auto letter:st){
		    if(letter == ')') cnt--;
		    else if(letter == '(')cnt++;
		    res = max(cnt, res);
	    }
	    return res;
    }
    int maxDepth(string s) {
	    return solve(s);
    }
};
