class Solution {
public:
    /*
        time: O(n)
        space: O(n)
	elapsed time: 9 min.
     * */
    int solve(vector<int> &nums){
	unordered_set<int> data;
	int maxNeg = nums.front();
	for(auto i:nums){
	       	if(i>=0)data.insert(i);
		maxNeg = max(maxNeg, i);
	}
	if(data.empty())return maxNeg;
	int res = 0;
	for(auto i:data) res+=i;
	return res;
    }
    int maxSum(vector<int>& nums) {
        return solve(nums);
    }
};
/*

    1 2 -1 -2 1 0  -1
            l
                   i
    1, 2, -1, -2, 

 * */
