class Solution {
public:
    // 1 0 1 0 1 k =3
    // 1 1 0 1 1
    // 1 1 1 0 0
    int solve(vector<int> &nums, int k){
	    int n = nums.size(), res = 0;
	    for(int i = 0; i < n; i++){
		    if( nums[i] == 0){
			    for(int j = 0; j < k && i+j < n; j++){
				    nums[i+j] ^= nums[i+j];
				    res++;
			    }
		    }
	    }
	    for(int i = 0 ; i < n; i++){
		    if(nums[i]==0)return -1;
	    }
	    return res;
    }
    int minKBitFlips(vector<int>& nums, int k) {
	    return solve(nums, k);
    }
};
