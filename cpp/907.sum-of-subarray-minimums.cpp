class Solution {
public:
    int solve(vector<int> &arr){
	long long MOD = 1e9+7;
        int n = arr.size(), res = 0;
	for(int i = 0 ; i < n ; i++){
	   int minv = INT_MAX;
	   for(int j = i; j <n; j++){
		   minv=min(minv, arr[j]);
		   res = (res+minv)%MOD;
	   }
	}
	return res;
    }
    int sumSubarrayMins(vector<int>& arr) {
	    return solve(arr);
    }
};
