class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int indexDiff, int valueDiff) {
         multiset<int> values;
         int n = nums.size();
	 int k = indexDiff;
         for(int i = 0 ; i < n; i++){
		 auto it = values.lower_bound(nums[i]);
		 if(it != values.end() && *it-nums[i] <= valueDiff)return true;
		 if( it!=values.begin()){
			 it--;
			 if(nums[i]-*it<=valueDiff)return true;
		 }
		 values.insert(nums[i]);
		 if(i>=k){
		      auto it = values.find(nums[i-k]);
		      values.erase(it);
		 }
	 }	 
	 return false;
    }
};
