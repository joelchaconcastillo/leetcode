class Solution {
public:

    long long solve(vector<int> &nums, int k, vector<vector<int> > &edges){
       int n = nums.size(), cont = 0, min_delta=INT_MAX;
       long long current = 0;
       for(auto num:nums){
	   int xor_val = num^k;
	   if(xor_val > num){
	      cont++;
	      current+=xor_val;
	      min_delta = min(min_delta, xor_val - num);
	   }else{
	      current+=num;
	      min_delta = min(min_delta, num-xor_val);
	   }
       }
       if(cont%2!=0){
	   return current - min_delta;//undo the last change
       }
       return current;
    }
    long long dp2(vector<int> &nums, int k, int index, int parity_xor, vector<vector<long long> > &memo){
	 if(index == nums.size()){
	     if(parity_xor)return 0;
	     return INT_MIN;
	 }
	 if(memo[index][parity_xor] != -1)return memo[index][parity_xor];
	 long long res = 0;
	 res = max(res, dp2(nums, k, index+1, parity_xor, memo)+nums[index]);
	 res = max(res, dp2(nums, k, index+1, parity_xor^1, memo)+(nums[index]^k));
	 return memo[index][parity_xor] = res;
    }
    long long solve1(vector<int> &nums, int k, vector<vector<int> > &edges){
	  int n = nums.size();
	  vector<vector<long long>> memo(n, vector<long long> (2, -1));
	  return dp2(nums, k, 0, 1, memo);
    }
    
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
       return solve(nums, k, edges);
       return solve1(nums, k, edges);
    }
};
