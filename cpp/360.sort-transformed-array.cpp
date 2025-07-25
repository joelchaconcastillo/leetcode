class Solution {
public:
    int f(int a, int b, int c, int x){
	    return a*x*x+b*x+c;
    }
    vector<int> solve(vector<int> &nums, int a, int b, int c){
	    int n = nums.size();
	    vector<int> res;
	    if(a<=0){
		    int l = 0, r = n-1;
		    while(l<=r){
			    int eval1 = f(a,b,c,nums[l]);
			    int eval2 = f(a,b,c,nums[r]);
			    if(eval1 < eval2) res.push_back(eval1), l++;
			    else res.push_back(eval2), r--;
		    }
	    }else if(a>0){
		    int minidx=0, minval=INT_MAX;
		    for(int i = 0 ; i < n; i++){
			    int eval = f(a,b,c,nums[i]);
			    if(eval < minval){
				    minval = eval;
				    minidx = i;
			    }
		    }
		    int l=minidx, r=minidx+1;
		    while(l>=0 && r<n){
			    int eval1 = f(a,b,c,nums[l]);
			    int eval2 = f(a,b,c,nums[r]);
			    if(eval1 < eval2) res.push_back(eval1), l--;
			    else res.push_back(eval2), r++;
		    }
		    while(l>=0) res.push_back(f(a,b,c,nums[l--]));
		    while(r<n) res.push_back(f(a,b,c,nums[r++]));
	    }
	    return res;
    }
    vector<int> sortTransformedArray(vector<int>& nums, int a, int b, int c) {
	    return solve(nums, a, b, c);
    }
};
