class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
	int n = nums.size(), res = 0;
	if(n<=2)return 0;
	// x+y > z 
	// x+y-z>0
	// x<y<z
	// 0 1 2 3
	// 2 2 3 4
	// x 
	//     y
	//         k 
	//  +1+1+1
	for(int i = 0 ;i < n; i++){
		for(int j = i+1; j < n; j++){
			int k = lower_bound(nums.begin()+j+1, nums.end(), nums[i]+nums[j])-nums.begin();
			if(k==n)k--;
			if(nums[i]+nums[j] <= nums[k])k--;
			res += max(0,k-j);
		}
	}
	return res;
    }
};
