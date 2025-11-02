class Solution {
public:
    vector<vector<int> > solve(vector<int> &nums){
	  sort(nums.begin(), nums.end());
	  int n = nums.size();
	  vector<vector<int> > res;
	  // -4 -1 -1 0 1 2
	  //    i
	  //        j
	  //      
	  for(int i = 0 ; i < n; i = upper_bound(nums.begin()+i, nums.end(), nums[i])-nums.begin()){
	      for(
			      int j = i+1; 
			      j < n; j = upper_bound(nums.begin()+j, nums.end(), nums[j])-nums.begin()
			      ){
		      int target = -nums[i]-nums[j];
		      auto it = lower_bound(nums.begin()+j+1, nums.end(), target);
		      if(it==nums.end())continue;
		      if((*it)+nums[i]+nums[j] != 0)continue;
		      res.push_back({nums[i], nums[j], target});

	      }
	  }
	  return res;
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        return solve(nums);	    
    }
};
