class Solution {
public:
    int solve(vector<int>& nums) {
	    vector<int> res = nums;
	    int n = res.size();
	    while(n>1){
		    for(int i = 0 ; 2*i < n ;i++){
			    int val = 0;
			    if(i%2==0){
				 val = min(res[2*i], res[2*i+1]);
			    }else{
				 val = max(res[2*i], res[2*i+1]);
			    }
			    res[i] = val;
		    }
		    n/=2;
	    }
	    return res[0];
    }
    int minMaxGame(vector<int>& nums) {
	return solve(nums);
    }
};
