class Solution {
public:
    int partitions(vector<int> &nums, long long maxv){
	    int cont = 0, current=0;
	    for(auto num:nums){
		    if(current^num > maxv){
			    current=num;
			    cont++;
		    }else current ^=num;
	    }
	    if(current!=0)cont++;
	    return cont;
    }
    int solve1(vector<int>& nums, int k) {
	    long long lo = 0, hi = INT_MAX/2;
	    while(lo<hi){
		    long long mid = (lo+hi)/2;
		    if( partitions(nums, mid) <= k)
			    hi=mid;
		    else lo=mid+1;
	    }
	    return lo;
    }
    int memo[1000][1000];
    int dfs(vector<int> &nums, int k, int idx){
	    if(k<0)return INT_MAX;
	    if(idx==nums.size()){
		    if(k!=0)return INT_MAX;
		    return 0;
	    }
	    if(memo[idx][k]!=-1)return memo[idx][k];
	    int res = INT_MAX, current = 0;
	    for(int i = idx;i < nums.size(); i++){
		    current ^=nums[i];
		    res = min(res, 
				    max(
					    current, 
					    dfs(nums, k-1, i+1)
					    )
				    );
	    }
	    return memo[idx][k]=res;
    }
    int solve2(vector<int>& nums, int k) {
	    memset(memo, -1, sizeof memo);
	    return dfs(nums, k, 0);
    }
    int minXor(vector<int>& nums, int k) {
	    return solve2(nums, k);
    }
};
