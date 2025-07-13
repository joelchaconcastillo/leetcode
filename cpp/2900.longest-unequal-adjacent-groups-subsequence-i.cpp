class Solution {
public:
    vector<string> solve(vector<string> &words, vector<int> &groups){
	    //dp[i] - longest laternated sub-sequence!!!
	    // dp[i] = max(dp[i], dp[j]+1) if dp[j] != dp[i] on groups
	    int n = words.size();
	    vector<int> dp(n,1), parent(n, -1);
	    pair<int, int> maxindex(1,0);
	    for(int i = 1 ; i <n ;i++){
		    for(int j = 0; j < i; j++){
			    if( groups[i] == groups[j] )continue;
			    if(dp[j]+1 > dp[i]){
				    dp[i] = dp[j]+1;
				    parent[i]=j;
			    }
		    }
		    maxindex = max(maxindex, {dp[i],i});
	    }
	    if(maxindex.first == -1) return {};
	    vector<string> res;
	    int current = maxindex.second;
	    while(current!=-1){
		    res.push_back(words[current]);
		    current = parent[current];
	    }
	    reverse(res.begin(), res.end());
	    return res;
    }
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
	    return solve(words, groups);
    }
};
