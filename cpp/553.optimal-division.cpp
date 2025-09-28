class Solution {
public:

    string solve1(vector<int> &nums){
	    int n = nums.size();
	    if( n == 1)return to_string(nums[0]);
	    if( n == 2) return to_string(nums[0])+"/"+to_string(nums[1]);
	    string den = "";
	    for(int i = 1; i < n; i++){
		    if(i>1)den+="/";
		    den += to_string(nums[i]);
	    }
	    return to_string(nums[0])+"/("+den+")";
    }
    string optimalDivision(vector<int>& nums) {
	    return solve1(nums);
    }
};
