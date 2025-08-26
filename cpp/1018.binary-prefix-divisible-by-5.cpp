class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
       int n = nums.size();
       vector<bool>res;
       int current = 0;
       for(int i = 0; i < n; i++){
	       current +=nums[i];
	       current%=5;
	       res.push_back(current==0);
	       current <<=1;
       }       
       return res;
    }
};
