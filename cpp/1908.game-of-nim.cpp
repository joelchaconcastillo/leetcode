class Solution {
public:
    unordered_map<string, bool> memo;
    string to_key(vector<int> &piles){
	    string st = "";
	    for(auto i:piles)st+=to_string(i);
	    return st;
    }
    bool dfs(vector<int> piles){
	    bool wins = false;
	    sort(piles.begin(), piles.end());
	    string key = to_key(piles);
	    if(memo.count(key))return memo[key];
	    for(int i = 0 ; i < piles.size(); i++){
		    if(piles[i]==0)continue;
		    for(int j = 1; j <= piles[i]; j++){
			    piles[i]-=j;
			    if(!dfs(piles)) wins=true;
			    piles[i]+=j;
		    }
	    }
	    return memo[key] = wins;
    }
    bool solve(vector<int> &piles){
	    return dfs(piles);
    }
    bool solve2(vector<int> &piles){
	    int res=0;
	    for(auto i:piles)res ^=i;
	    return res !=0;
    }
    bool nimGame(vector<int>& piles) {
	    return solve2(piles);
	    return solve(piles);
    }
};
