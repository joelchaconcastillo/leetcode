class Solution {
public:
    #define INT_MAX 100000
    //dp[i][j] --> min number of operations considering 0...i, and using 0...j
    typedef map<tuple<int, int>, int> my_type;
    int dfs(vector<int> &arr1, vector<int> &arr2, int i, int j, int prev, my_type &memo){
	if(i == arr1.size())return 0;
	if(memo.count({i, prev})) return memo[{i,prev}];
	int res = INT_MAX;
	if(arr1[i] > prev){
	    res = min(res, dfs(arr1, arr2, i+1, j, arr1[i], memo));
	}
	int start = upper_bound(arr2.begin()+j, arr2.end(), prev) - arr2.begin();
	if(start < arr2.size())
        res = min(res, dfs(arr1, arr2, i+1, start+1, arr2[start], memo)+1);
	return memo[{i,prev}] = res;
    }
    int solve(vector<int> &arr1, vector<int> &arr2){
	sort(arr2.begin(), arr2.end());
	arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
	my_type memo;
	auto res = dfs(arr1, arr2, 0, 0, -1, memo);
	if(res == INT_MAX)return -1;
	return res;
    }
    int bottom_up(vector<int> &arr1, vector<int> &arr2){
	int n = arr1.size(), m = arr2.size();
	sort(arr2.begin(), arr2.end());
	arr2.erase(unique(arr2.begin(), arr2.end()), arr2.end());
	//dp[i][j] -> min cost considering substring 0...i with prev value as j
        //base cases
	vector<map<int, int> > dp(n+1);

	dp[0][-1]=0;
	for(int i = 1; i <= n; i++){
	   for(auto [prev, val]:dp[i-1]){
	       if(prev < arr1[i-1]){
		       if(dp[i].count(arr1[i-1])==0) dp[i][arr1[i-1]]=INT_MAX;
		       dp[i][arr1[i-1]] = min(dp[i][arr1[i-1]], val);
	       }
	       int idx = upper_bound(arr2.begin(), arr2.end(),prev)-arr2.begin(); 
	       if(idx < arr2.size()){
		  if(dp[i].count(arr2[idx])==0) dp[i][arr2[idx]]=INT_MAX;
	          dp[i][arr2[idx]] = min(dp[i][arr2[idx]], val+1);
	       }
	   }
	}
	int res = INT_MAX;
	for(auto ii:dp[n]) res = min(res, ii.second);
	if(res == INT_MAX) return -1;
	return res;
    }
    int makeArrayIncreasing(vector<int>& arr1, vector<int>& arr2) {
	return bottom_up(arr1, arr2);
	return solve(arr1, arr2);
    }
};
