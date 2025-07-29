class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
	    if(nums.size() < 3)return 0;
	    nums.push_back(100000);
	    int delta = nums[1]-nums[0], l = 0, n = nums.size(), res=0;
	    for(int i = 0 ; i+1 < n; i++){
		    if(delta != nums[i+1]-nums[i]){
			    int dist = i-l+1;
			    dist = max(dist-2,0);
			    res += dist*(dist+1)/2;
			    l=i;
			    delta = nums[i+1]-nums[i];
		    }
	    }
	    return res;
    }
};
