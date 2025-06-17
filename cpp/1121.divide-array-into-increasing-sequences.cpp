class Solution {
public:
	//O(n)
    bool solve(vector<int> &nums, int k){
	 unordered_map<int, int> freq;
	 int number_sequences=0;
	 for(auto i:nums){
		 freq[i]++;
		 number_sequences = max(number_sequences, freq[i]);
	 }
	 vector<int>sequences(number_sequences,0);
	 int idx = 0;
	 for(auto [item, count]:freq){
		 while(count--){
			 sequences[idx]++;
			 idx = (idx+1)%number_sequences;
		 }
	 }

	 for(auto seq:sequences){
		 if(seq < k )return false;
	 }
	 return true;
    }
    bool solve_optimized(vector<int> &nums, int k){
	 unordered_map<int, int> freq;
	 int number_sequences=0;
	 for(auto i:nums){
		 freq[i]++;
		 number_sequences = max(number_sequences, freq[i]);
	 }
	 return nums.size() >= k*number_sequences;
    }
    bool canDivideIntoSubsequences(vector<int>& nums, int k) {
	    return solve_optimized(nums, k);
    }
};
