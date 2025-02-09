class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size(), res=0;
	for(int i = 0; i+1 < n; i++){
	   int left = 0, right = 0;
	   for(int j = 0; j<=i; j++) left+=nums[j];
	   for(int j = i+1; j<n; j++) right+=nums[j];
	   res += (left-right)%2 == 0;
	}
       return res;	
    }
};
