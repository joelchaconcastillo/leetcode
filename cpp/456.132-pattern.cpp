class Solution {
public:
    bool has_pattern(vector<int> &nums){
   int n = nums.size();
   vector<pair<int, int>> st;
   int min_val = INT_MAX;
   for(int i = 0 ;i < n; i++){
      while(!st.empty() && nums[i] >= st.back().first) st.pop_back();
      //check solution...
      if(!st.empty() && nums[i] > st.back().second) return true;
      st.push_back({nums[i], min_val});
      min_val = min(min_val, nums[i]);
   }
   return false;

    }
    bool find132pattern(vector<int>& nums) {
     return has_pattern(nums);   
    }
};
