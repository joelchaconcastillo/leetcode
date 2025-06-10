class Solution {
public:
    typedef tuple<int, vector<int> > my_type;

    vector<vector<my_type> > memo;
    my_type dp(vector<int> &nums, vector<int> &pref, int i, int k, int l){
	 if(l==0){
	    return {0,{INT_MAX, INT_MAX, INT_MAX}};
	 }
	 if(i+k-1 >= nums.size()){ // i=7, n=9, k = 2, ---> 
	    return {INT_MIN, {INT_MAX, INT_MAX, INT_MAX}};
	 }
	 if(get<0>(memo[i][l]) != -1) return memo[i][l];
	 int sum = pref[i+k]-pref[i];
	 auto [sum1, path1] = dp(nums, pref, i+k, k, l-1);
	 sum1+=sum;
	 path1[3-l] = i;
	 auto [sum2, path2] = dp(nums, pref, i+1, k, l);
	 if(sum1 > sum2) return memo[i][l] = {sum1, path1};
	 if(sum2 > sum1)  return memo[i][l] = {sum2, path2};
	 return memo[i][l] = {sum1, min(path1, path2)};
    }
    vector<int> solve(vector<int> &nums, int k){
	   int n = nums.size();
	   memo.assign(n+1, vector<my_type> (4,{-1, {INT_MAX, INT_MAX, INT_MAX}}));
	   vector<int> pref(n+1,0);
	   for(int i = 1; i <=n ;i++) pref[i] = pref[i-1]+nums[i-1];
	   auto [sum, path] = dp(nums, pref, 0, k, 3);
	   return path;
    }
    vector<int> sliding_window_solve(vector<int> &nums, int k){
	   int n = nums.size();
	   vector<int> window(3, 0), bests(3,0);
	   vector<vector<int> > indices = {{0}, {0, k}, {0, k, 2*k}};
	   for(int i = 0 ; i < k; i++) window[0] +=nums[i];
	   for(int i = k; i < 2*k; i++) window[1] +=nums[i];
	   for(int i = 2*k; i < 3*k; i++) window[2] +=nums[i];
	   bests[0] = window[0];
	   bests[1] = bests[0]+window[1];
	   bests[2] = bests[1]+window[2];
	   for(int i = 3*k; i < n; i++){
		   window[0] = window[0]-nums[i-3*k]+nums[i-2*k];
		   window[1] = window[1]-nums[i-2*k]+nums[i-k];
		   window[2] = window[2]-nums[i-k]+nums[i];
		   if(window[0] > bests[0]){
			   bests[0] = window[0];
			   indices[0] = {i-3*k+1};
		   }
		   if(bests[0]+window[1] > bests[1]){
			   bests[1] = bests[0]+window[1];
			   indices[1][0] = indices[0][0];
			   indices[1][1] = i-2*k+1;
		   }
		   if(bests[1]+window[2] > bests[2]){
			   bests[2] = bests[1]+window[2];
			   indices[2][0] = indices[1][0];
			   indices[2][1] = indices[1][1];
			   indices[2][2] = i-k+1;
		   }
	   }
	   return indices.back();
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
	  return sliding_window_solve(nums, k);
	  return solve(nums, k);
    }
};
