class Solution {
public:
    /*
        time: O(n^m) where n --> size of s, and m is number of words
        space: O(n)
	can be improved???
	yep using memo:
        time: O(n*m)
        space: O(n)
	can it be better?
	yep, on space using a dp - table

	dp[i] --> there is a match of the prefix on string s from start until index 'i'

	elapsed time to solve it: 8 min.
     * */
    unordered_map<int, bool> memo;
    /*
       
       words -->  a b c
       sentence --> cabc
     * */
    bool solve(string &s, vector<string> &words, int i){
	 if(i==s.size()){
	   return true;
	 }
	 if(memo.count(i))return memo[i];
	 bool hasSol=false;
	 for(auto &word:words){
            if(i+word.size() > s.size()) continue;
	    if(s.substr(i, word.size())!=word)continue;
	    hasSol |= (solve(s, words, i+word.size()));
	 }
	 return memo[i] = hasSol;
    }
    /*
        dp[i] = dp[i-j] & s.subtr(i-j, word.size()) == word
     * */
    bool solve_optimized(string &s, vector<string> &words){
	 int n = s.size();
	 vector<bool> dp(n+1, false);
	 dp[0]=true;
	 for(int i = 1; i <= n; i++){
	     for(auto &word:words){
		int m = word.size();
		int j = i-m; // i = 1, m = 1, j = 0
		if(j < 0 )continue;
		dp[i] = dp[i] || (dp[j] && s.substr(j, m)==word);
	     }
	 }
	 return dp.back();
    }
    bool wordBreak(string s, vector<string>& wordDict) {
       return solve_optimized(s, wordDict);
       //return solve(s, wordDict, 0);
    }
};
