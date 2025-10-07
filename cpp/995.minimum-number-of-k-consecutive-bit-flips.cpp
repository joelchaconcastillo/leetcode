class Solution {
public:
    int solve(vector<int> &nums, int k){
	    int n = nums.size();
	    vector<int> sums(n+1,0);
	    int current = 0, res = 0;
	    for(int i = 0; i < n; i++){
		    int val = nums[i];
		    current += sums[i];
		    if(current%2==1)val = 1-val;
		    if(val==0 && i+k-1<n){
		       current++;
		       if(i+k<n) sums[i+k]--;
		       val=1;
		       res++;
		    }
		    nums[i]=val;
	    }
	    for(auto i:nums)if(i==0)return -1;
	    return res;
    }
    int minKBitFlips(vector<int>& nums, int k) {
	    return solve(nums, k);
    }
};
