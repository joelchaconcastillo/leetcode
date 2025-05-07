class Solution {
public:
    int solve(vector<int> &nums){
	  unordered_set<int> res(nums.begin(), nums.end()), tmp;
	  for(auto i:res){
	     string st = to_string(i);
	     reverse(st.begin(), st.end());
	     tmp.insert(stoi(st));
	  }
	  for(auto i:tmp)res.insert(i);

	  return res.size();
    }
    int countDistinctIntegers(vector<int>& nums) {
	return solve(nums);
    }
};
