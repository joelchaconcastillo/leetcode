class Solution {
public:

    int findMaximumXOR(vector<int>& nums) {
       int n = nums.size(), res=0, mask=0;
       for(int i = 31; i >=0 ; i--){
	       mask |= (1<<i);
	       unordered_set<int> pref;
	       for(auto num:nums)pref.insert(num&mask);
	       int attempt_mask = res|(1<<i);
	       for(auto p:pref){
		       if(pref.count(p^attempt_mask)){
			       res = attempt_mask;
			       break;
		       }
	       }
       }
       return res;
    }
};
