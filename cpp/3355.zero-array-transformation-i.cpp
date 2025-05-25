class Solution {
public:
    bool solve(vector<int> &nums, vector<vector<int> > &queries){
	 int n = nums.size(), m = queries.size();
	 vector<int> prefix(n+2,0); 
	 for(auto q:queries){
	     int l = q[0]+1, r = q[1]+1;
	     prefix[l]--;
	     prefix[r+1]++;
	 }
	 for(int i = 1; i<=n+1; i++)prefix[i] +=prefix[i-1];
	 for(int i = 0 ; i < n; i++){
	    nums[i] = max(0, nums[i]+prefix[i+1]);
	 }
	 for(auto i:nums)if(i!=0)return false;
	 return true;
    }
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
	 return solve(nums, queries);
    }
};
/*
   for(int i = n-1; i >=0; i--){
      maxv = max(maxv, prices[i]);
      res = max(res, max(0, maxv-prices[i]));
   }
 * */
