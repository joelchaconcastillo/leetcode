class Solution {
public:
    vector<int> solve(vector<vector<int> > &nums){
	  int n = nums.size();
	  vector<int> res = {0, INT_MAX};
	  typedef tuple<int, int, int> my_type;
	  priority_queue<my_type, vector<my_type>, greater<>> pq;
	  int maxv = INT_MIN;
	  for(int i = 0 ; i < n; i++){
		  pq.push({nums[i][0], i, 0});
		  maxv = max(maxv, nums[i][0]);
	  }
	  while(pq.size() == n){//we always must have at least one item per list
		  auto [value, i, j] = pq.top(); pq.pop();
		  if( res[1]-res[0] > maxv-value){
			  res = {value, maxv};
		  }
		  if(j+1 < nums[i].size()){
		    pq.push({nums[i][j+1], i, j+1});
		    maxv = max(nums[i][j+1], maxv);
		  }
	  }
	  return res;
    }
    vector<int> smallestRange(vector<vector<int>>& nums) {
	    return solve(nums);
    }
};
