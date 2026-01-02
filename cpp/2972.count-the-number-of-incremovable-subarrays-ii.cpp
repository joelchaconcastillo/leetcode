class Solution {
public:
    long long incremovableSubarrayCount(vector<int>& nums) {
         int n = nums.size();
	 long long res = 0;
	 vector<int> start, end;
	 int prev = INT_MIN;
	 for(int i = 0 ; i < n; i++){
		 if(prev < nums[i])start.push_back(nums[i]);
		 else break;
		 prev = nums[i];
	 }
	 prev = INT_MAX;
	 for(int i = n-1; i >=0; i--){
		 if(nums[i] < prev) end.push_back(nums[i]);
		 else break;
		 prev = nums[i];
	 }
	 if(start.size()+end.size() > n)return 1LL*n*(n+1LL)/2LL;
	 reverse(end.begin(), end.end());
	 res += start.size()+end.size();
	 int i = 0, j = 0;
	 while(i <start.size() && j < end.size()){
		 if( start[i] < end[j]){
			 res += end.size()-j;
			 i++;
		 }else j++;
	 }
	 return res+1;
    }
};
