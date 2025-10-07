class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
         int n = nums.size(), rem = n;
         vector<int> st;
	 for(int i = 0 ; i < n; i++){
		 while(!st.empty() &&
				 st.back() > nums[i] &&
				 st.size()-1+rem >= k){
			 st.pop_back();
		 }
		 rem--;
		 if(st.size() < k) st.push_back(nums[i]);
	 }
         return st;	 
    }
};
