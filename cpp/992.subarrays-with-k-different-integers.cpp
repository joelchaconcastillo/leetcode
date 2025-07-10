class Solution {
public:
    int solve(vector<int> &nums, int k){
	    return subWithAtMost(nums, k)-subWithAtMost(nums, k-1);
    }
    int subWithAtMost(vector<int> &nums, int k){
	    int n = nums.size(), l = 0;
	    unordered_map<int, int> freq;
	    int res = 0;
	    for(int i = 0 ;i  < n ; i++){
		    freq[nums[i]]++;
		    while(freq.size() > k){
			    freq[nums[l]]--;
			    if(freq[nums[l]]==0) freq.erase(nums[l]);
			    l++;
		    }
		    res += (i-l+1);
	    }
	    return res;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
	    return solve(nums, k);
    }
};
/*
 Input: nums = [1,2,1,2,3], k = 2
            K:1           --> 5
            K:2 
   1  2  1  2  3     k = 2
   l
               r
   
   a b a b a b a
       l
         r

   1  2  1  2
            a        
            b



   1  2 
   1  2  1
   1  2  1  2
   ---
   2  1
   2  1  2
   1  2
   2  3

Output: 7
Explanation: Subarrays formed with exactly 2 different integers: [1,2], [2,1], [1,2], [2,3], [1,2,1], [2,1,2], [1,2,1,2]

 * */
