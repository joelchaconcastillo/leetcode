class Solution {
public:
    int sumOfDigits(vector<int>& nums) {
	int minv = nums[0]+1, minsum=0;
        for(auto num:nums){
		if(num >= minv)continue;
		minv=num;
	        int sum = 0;
		while(num){
			sum+=num%10;
			num/=10;
		}
		minsum = sum;
	}		
	return minsum%2==0;
    }
};
