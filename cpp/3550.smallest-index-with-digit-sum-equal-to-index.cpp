class Solution {
public:
    int smallestIndex(vector<int>& nums) {
	    int n = nums.size();
	    for(int i = 0 ; i < n ;i++){
		    int sum = 0, num=nums[i];
		    while(num){
			    sum+=num%10;
			    num/=10;
		    }
		    if(sum==i)return i;
	    }
	    return -1;
    }
};
