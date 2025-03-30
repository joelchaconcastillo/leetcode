class Solution {
public:
	//time: O(n)
	//space: O(1)
	//elapsed time to resolve: 6 min.
    int solve(string &s){
	int n = s.size();
	int res = 0;
	for(int i = 0 ;i < n; i++){
	   int rev = 26-(s[i]-'a');
	   res += (i+1)*(rev);
	}
	return res;
    }
    int reverseDegree(string s) {
	    return solve(s);
    }
};
