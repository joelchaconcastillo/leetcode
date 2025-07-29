class Solution {
public:
    int solve(vector<int> &nums){
       int n = nums.size(); 
       vector<int> left(n), right(n);
       int count = 0;
       for(int i = 0; i < n ; i++){
	       if(nums[i]==1)count++;
	       else count = 0;
	       left[i]=count;
       }
       count = 0;
       for(int i = n-1; i>=0; i--){
	       if(nums[i]==1)count++;
	       else count = 0;
	       right[i]=count;
       }
       int res = 0;
       for(int i = 0 ; i <n; i++){
	       if( nums[i] == 0 ){
		       int val = 1;
		       if(i>0)val += left[i-1];
		       if(i+1<n) val += right[i+1];
		       res = max(res, val);
	       }else res = max(left[i], res);
       }
       return res;

    }
    int solve2(vector<int> &nums){
	    //   1 1 0 1 0 1 0 1 1
	    // z 1 2 3 4 2 3 2 3 4
	    // o 1 2 0 1 0 1 0 1 2
	    int n = nums.size();
	    int contZero = 0, contOne=0, res=0;
	    for(int i = 0 ;i < n; i++){
		if(nums[i]==0){
			contZero = contOne+1;
			contOne = 0;
		}else{
			contOne++;
			contZero++;
		}
		res = max(res, contZero);
		res = max(res, contOne);
	    }
	    return res;
    }
    int findMaxConsecutiveOnes(vector<int>& nums) {
	    return solve2(nums);
	    return solve(nums);
    }
};
