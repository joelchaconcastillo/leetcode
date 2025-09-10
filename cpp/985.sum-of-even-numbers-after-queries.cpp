class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
          int sum = 0;
          for(auto num:nums) if(num%2==0) sum+=num;
	  vector<int> res;
	  for(auto query:queries){
		  int idx = query[1], val = query[0];
		  if(nums[idx]%2==0)sum-=nums[idx];
		  nums[idx] += val;
		  if(nums[idx]%2==0)sum+=nums[idx];
		  res.push_back(sum);
	  }
	  return res;
    }
};
