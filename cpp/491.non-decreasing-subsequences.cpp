class Solution {
public:
	// time: O( 2^n log 2^n)
    set<vector<int>>marked; 
    void combinations(int idx, vector<int> &current, vector<int> &nums, vector<vector<int>> &res){
	  if(idx == nums.size()){
	     if(current.size() <= 1)return;
	     if(marked.count(current)) return;
	     marked.insert(current);
	     res.push_back(current);
	     return;
	  } 
	  if( current.empty() || (current.back() <= nums[idx])){
	    current.push_back(nums[idx]);
	    combinations(idx+1, current, nums, res);
	    current.pop_back();
	  }
	  combinations(idx+1, current, nums, res);

    } 
    vector<vector<int> > solve1(vector<int>&nums){
	  vector<vector<int >> res;
	  vector<int> current;
	  combinations(0, current, nums, res);
	  return res;
    }
    void dfs(int idx, vector<int> &current, vector<int> &nums, vector<vector<int> > &res){
	    if(current.size()>1)res.push_back(current);

	    unordered_set<int> marked;
	    for(int i=idx; i < nums.size(); i++){
		if( (current.empty() || current.back()<=nums[i])
				&& !marked.count(nums[i])){
		  current.push_back(nums[i]);
	          dfs(i+1, current, nums, res);
		  current.pop_back();
		  marked.insert(nums[i]);
		}
	    }
    }
    vector<vector<int> > solve2(vector<int>&nums){
	  vector<vector<int >> res;
	  vector<int> current;
	  dfs(0, current, nums, res);
	  return res;
    }
    vector<vector<int>> findSubsequences(vector<int>& nums) {
	    //return solve1(nums);
	    return solve2(nums);
    }
};
///  
/// 1 2 7 6 10 11 12
