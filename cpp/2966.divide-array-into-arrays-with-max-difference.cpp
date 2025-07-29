class Solution {
public:
    vector<vector<int> > solve(vector<int> &nums, int k){
	    int n = nums.size();
	    sort(nums.begin(), nums.end());
	    vector<vector<int> >res;
	    for(int i = 0 ; i <n; i+=3){
		    if(nums[i+1]-nums[i] > k || nums[i+2]-nums[i+1] > k || nums[i+2]-nums[i] > k)return {};
		    vector<int> row(3);
		    row[0] = nums[i];
		    row[1] = nums[i+1];
		    row[2] = nums[i+2];
		    res.push_back(row);
	    }
	    return res;
    }
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
	    return solve(nums, k);
    }
};
