class Solution {
public:
    vector<int> solve(vector<int> &nums){
	 int cnt1 = 0, cnt2 = 0;
	 vector<int> res;
	 for(auto i:nums){
	    if(i%2 == 0)cnt2++;
	    else cnt1++;
	 }
	 while(cnt2--)res.push_back(0);
	 while(cnt1--)res.push_back(1);
	 return res;
    }
    vector<int> transformArray(vector<int>& nums) {
	  return solve(nums);
    }
};
