class Solution {
public:
    //marked 1 1 0 1 
    //       1 2 3 4
    //             l
    //path:  1 2 4
    //results=
    //         1 2 3 4
    void bk(int level, vector<int> &nums, vector<int> &path, vector<vector<int> > &result, vector<bool> &marked){
	 if(level == 0){
	     result.push_back(path);
	     return;
	 }
	 for(int i = 0 ;i < nums.size(); i++){
            if(marked[i])continue;
	    marked[i] = true;
	    path.push_back(nums[i]);
	    bk(level-1, nums, path, result, marked);
	    marked[i] = false;
	    path.pop_back();
	 }
    }    
    vector<vector<int> > solve(vector<int> &nums){
	  vector<vector<int> > res;
	  vector<int> path;
	  vector<bool> marked((int) nums.size());
	  bk(nums.size(), nums, path, res, marked);
	  return res;
    }
    vector<vector<int>> permute(vector<int>& nums) {
	  return solve(nums);
    }
};
