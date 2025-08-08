class Solution {
public:
    int solve(vector<int> &arr){
	    int res = 0, n = arr.size();
	    unordered_set<int> marked(arr.begin(), arr.end());
	    for(int i = 0 ;i  <n ;i++){
		    for(int j = i+1; j < n; j++){
			    int current_len = 2;
			    int a = arr[i], b = arr[j];
			    while(marked.count(a+b)){
				    int tmp = a+b;
				    a=b;
				    b=tmp;
				    current_len++;
			            res = max(res, current_len);
			    }
		    }
	    }
	    return res;
    }
    int solve2(vector<int> &arr){
	    int res = 0, n = arr.size();
	    vector<vector<int> > dp(n, vector<int> (n, 0));
	    unordered_map<int, int> val2idx;
	    for(int i = 0 ; i < n; i++){
		    val2idx[arr[i]]=i;
		    for(int j = 0; j < i; j++){
			    int diff = arr[i]-arr[j];
			    int prevIdx = -1;
			    if(val2idx.count(diff))prevIdx = val2idx[diff];
			    if(diff < arr[j] && prevIdx!=-1){
				    dp[j][i] = dp[prevIdx][j]+1;
			    }else dp[j][i] = 2;
			    res = max(res, dp[j][i]);
		    }
	    }
	    return res>2?res:0;
    }
    int lenLongestFibSubseq(vector<int>& arr) {
	    return solve2(arr);
	    return solve(arr);
    }
};
/*
        [1,2,3,4,5,6,7,8]
	 
	 
 * */
