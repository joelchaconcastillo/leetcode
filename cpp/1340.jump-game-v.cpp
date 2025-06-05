class Solution {
public:
    int dp1(vector<int> &arr, int idx, int d, vector<int> &memo){
	if(d == 0)return 1;
	if(idx == arr.size()) return 0;
	if(memo[idx]!=-1)return memo[idx];
	int l=idx-1, r=idx+1, res = 1;
	while(l>=0 && arr[idx] > arr[l] && idx-l <=d ){
		res = max(res, dp1(arr, l, d, memo)+1);
		l--;
	}
	while(r < arr.size() && arr[idx] > arr[r] && r-idx <=d){
		res = max(res, dp1(arr, r, d, memo)+1);
		r++;
	}
	return memo[idx] = res;
    }
    int solve(vector<int> &arr, int d){
	int res = 0;
	vector<int> memo(arr.size(), -1);
	for(int i = 0 ; i < arr.size(); i++)
	res =  max(res, dp1(arr, i, d, memo));
	return res;
    }
    int solve2(vector<int> &arr, int d){
	int n = arr.size(), res = 0;
	vector<int> dp(n, 1);
	for(int i = 0; i  < n; i++){
	   bool changed = false;
	   auto prev = dp;
	   for(int j = 0 ; j <n; j++){
	      int l = j-1, r = j+1;
	      while(l >=0 && j-l<=d && arr[j] > arr[l]){
		   dp[j] = max(dp[j], prev[l]+1);
		   l--;
	      }
	      while(r < n && r-j<=d && arr[j] > arr[r]){
		   dp[j] = max(dp[j], prev[r]+1);
		   r++;
	      }
	      if(dp[j]!=prev[j])changed=true;
	      res =  max(res, dp[j]);
	   }
	      prev = dp;
	      if(!changed) return res;
	}
	return res;
    }
    int maxJumps(vector<int>& arr, int d) {
	return solve(arr, d);
    }
};
