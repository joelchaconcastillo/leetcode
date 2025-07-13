class Solution {
public:

    int subarrays_k(std::vector<int> &nums, int goal){
	    int n = nums.size(), l = 0, res = 0, current_sum = 0;
	    for(int i = 0 ; i < n; i++){
		    current_sum += nums[i];
		    while(l<=i && current_sum > goal){
			    current_sum -= nums[l++];
		    }
		    res += (i-l+1);
	    }
	    return res;
    }
    int Solve2(std::vector<int> &nums, int goal){
	    return subarrays_k(nums, goal)-subarrays_k(nums, goal-1);
    }	    
    int Solve(std::vector<int> &nums, int goal){
	    int l = 0, n = nums.size(), res = 0, current_sum= 0, zeros = 0;
	    for(int i =0 ; i < n; i++){
		    current_sum+= nums[i];
		    while(l < i && (current_sum> goal || nums[l]==0)){
			    if(nums[l]) zeros = 0;
			    else zeros ++;
			    current_sum-=nums[l];
			    l++;
		    }
		    if(current_sum == goal){
			    res+=1+zeros;
		    }
	    }
	    return res;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
	    return Solve2(nums, goal);
	    return Solve(nums, goal);
    }
};
