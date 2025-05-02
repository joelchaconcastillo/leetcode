class Solution {
public:
    int solve2(vector<int> &nums){
	int n = nums.size();
	if( n ==1 )return n;
	int last = nums.front(), counter = 0;
	for(int i = 0 ; i < n; i++){
		if(nums[i]>= last){
			last = nums[i];
			counter++;
		}
	}
	return counter;
    }
    int solve(vector<int> &nums){
      int n = nums.size();
      vector<int> st;
      for(int i = n-1; i>=0 ;i--){
       while(!st.empty() && st.back() < nums[i]) st.pop_back();
       st.push_back(nums[i]);
      }
     return (int)st.size();
    }
    int maximumPossibleSize(vector<int>& nums) {
       return solve2(nums);    
    }
};
