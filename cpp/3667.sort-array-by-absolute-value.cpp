class Solution {
public:
    vector<int> sortByAbsoluteValue(vector<int>& nums) {
	sort(nums.begin(), nums.end(), [](const int a, const int b){
			  return a*a < b*b;
			});
        return nums;	    
    }
};
