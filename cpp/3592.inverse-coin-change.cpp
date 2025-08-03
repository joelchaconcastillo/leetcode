//  [0,1,0,2,0,3,0,4,0,5]
// 2 0 1 0 1 0 2 0 2 0 3  
// 4 0 1 0 1 0 1 0 1 0 2
// 6 0 1 0 1 0 1 0 0 0 1
//   2 4 6
//   
//   4 6    
//   2 2 6      
//   2 2 2 2 2    x
//   4 4 2      
//   2 2 2 4     x
class Solution {
public:
    vector<int> solve(vector<int> &nums){
	    int n = nums.size();
	    nums.insert(nums.begin(), 1);
	    vector<int> res;
	    for(int i = 1 ; i <= n; i++){
		    if(nums[i]>1)return {};
		    if(nums[i]==0) continue;
		    res.push_back(i);
		    for(int j = n; j>=i; j--){
			    nums[j] -= nums[j-i];
			    if(nums[j] < 0) return {};
		    }
	    }
	    return res;
    }
    vector<int> findCoins(vector<int>& numWays) {        
	    return solve(numWays);
    }
};
