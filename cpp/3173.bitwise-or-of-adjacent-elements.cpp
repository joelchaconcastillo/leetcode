class Solution {
public:
    vector<int> orArray(vector<int>& nums) {
      vector<int> res;
      int n = nums.size();
      for(int i = 0 ; i+1 <n ; i++){
	      res.push_back(nums[i]|nums[(i+1)%n]);
      }
      return res;
    }
};
