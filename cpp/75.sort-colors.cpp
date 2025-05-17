class Solution {
public:
    void solve1(vector<int> &nums){
	    vector<int> counters(3,0);
	    for(auto i:nums)counters[i]++;
	    int n = nums.size();
	    for(int i = 0 ; i < n; i++){
		for(int j = 0 ; j <= 2; j++)
		if(counters[j]>0){
			nums[i]=j;
		       	counters[j]--;
			break;
		}
	    }
    }
    void sortColors(vector<int>& nums) {
	    return solve1(nums);
    }
};
