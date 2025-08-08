class Solution {
public:
    bool canBeDone(int maxAllowed, vector<int> &nums, int p){
	    int i = 0, n = nums.size(), current_pairs=0;
	    while(i+1<n){
		    if(nums[i+1]-nums[i] <= maxAllowed){
			    i+=2;
			    current_pairs++;
		    }else i++;
	    }
	    return p<=current_pairs;
    }
    int solve(vector<int> &nums, int p){
	    if(p==0) return 0;
	    sort(nums.begin(), nums.end());
	    int lo=0, hi=nums.back()-nums.front();
	    while(lo<hi){
		    int mid =(lo+hi)/2;
		    if(canBeDone(mid, nums, p)){
			    hi=mid;
		    }else lo=mid+1;
	    }//
	    return lo;
    }
    int minimizeMax(vector<int>& nums, int p) {
	    return solve(nums, p);
    }
};

/*
  nums = [10,1,2,7,1,3], p = 2
          1 1 2 3 7 10
	   0 1 1 4 3
	  1 1 2 100 101
	   
 * */
