class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
	    int n = nums.size();
	    int max_v= INT_MIN, cont1=0;
	    for(int i = 0; i < n; i++){
		    if(nums[i] < max_v) cont1++;
		    max_v = max(max_v, nums[i]);
	    }
	    int cont2 = 0, min_v=INT_MAX;
	    for(int i = n-1; i >=0; i--){
		    if(nums[i] > min_v) cont2++;
		    min_v = min(min_v, nums[i]);
	    }
	    return min(cont1, cont2) <=1;
    }
};
// 4 6 8 1 2 3
// 1 3 5 3 8 9
// -inf 2 2 3 inf
//        p
//      i
// [5,7,7,8] 
//    p
//      i
//  4 2 3
