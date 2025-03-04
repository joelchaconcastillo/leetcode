class Solution {
public:
    /*
        time: O(n)
        space: O(1)
	elapsed time to solve: 3 min. 
     * */
    void moveZeroes(vector<int>& nums) {
	 int n = nums.size(), j = 0;
	 for(int i = 0 ;i < n; i++){
            if(nums[i]!=0) swap(nums[i], nums[j++]);
	 }
    }
};
/*
    [ 1, 1, 0, 0, 0, 1]
                     i
            j
 * */
