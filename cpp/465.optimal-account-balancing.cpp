class Solution {
public:
    int dfs(vector<int> &debt, vector<int> savings, int idx){
	    if(idx == debt.size()){
		    return 0;
	    }
	    if(debt[idx]==0){
		return dfs(debt, savings, idx+1);
	    }
	    int res = INT_MAX;
	    for(int i = 0 ; i < savings.size(); i++){
		if(savings[i]==0)continue;
		int delta = min(savings[i], debt[idx]);//5 - 2 --> 33
		savings[i] -= delta;
		debt[idx] -=delta;
		res = min(res, dfs(debt, savings, idx)+1);
		savings[i] += delta;
		debt[idx] += delta;
	    }
	    return res;
    }
    int solve(vector<vector<int> > &transactions){
	int n = transactions.size();
	unordered_map<int, int> total;
	for(auto transaction:transactions){
		 total[transaction[1]]+=transaction[2];
		 total[transaction[0]]-=transaction[2];
	}
	vector<int> debt, savings;
	for(auto ii:total){
		if(ii.second > 0) savings.push_back(ii.second);
		else if(ii.second < 0) debt.push_back(-ii.second);
	}
	int res = dfs(debt, savings, 0);
	return res;
    }
    int dfs(int mask, vector<int> &memo, vector<int> &creditList){
	 if(memo[mask]!=-1) return memo[mask];
	 int balancedSum = 0, res = 0;
	 for(int i = 0 ; i < creditList.size(); i++){
	     int current_mask = (1<<i);
	     balancedSum += creditList[i];
	     res = max(dfs(mask^current_mask, memo, creditList), res);
	 }
	 return memo[mask] = (res+(balancedSum == 0));
    }
    int solve2(vector<vector<int> > &transactions){
	    unordered_map<int, int>  credit_dict;
	    for(auto t:transactions){
		    credit_dict[t[0]] += t[2];
		    credit_dict[t[1]] -= t[2];
	    }
	    vector<int> creditList;
	    for(auto amount: credit_dict){
		 if(amount.second != 0) creditList.push_back(amount.second);
	    }
	    int n = creditList.size();
	    vector<int> memo(1<<n, -1);
	    memo[0] = 0;
	    return n - dfs((1<<n)-1, memo, creditList);
    }
    int minTransfers(vector<vector<int>>& transactions) {
	return solve(transactions);
    }
};
