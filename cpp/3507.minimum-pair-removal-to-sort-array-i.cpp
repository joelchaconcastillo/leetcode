class Solution {
public:
    int is_non_decreasing(vector<int> &current){
	    int n = current.size();
	    for(int i = 0 ; i+1< n; i++){
		    if(current[i] > current[i+1]) return false;
	    }
	    return true;
    }
    // time: O(n*n)
    // space: O(n)
    int solve(vector<int> &nums){
	int n = nums.size(), res = 0;
	vector<int> current = nums;
	while(!is_non_decreasing(current)){
	   vector<int> tmp;
	   int min_sum = INT_MAX;
   	   int index = -1;
	   for(int i = 0; i+1 < current.size() ;i++){
		   if(current[i]+current[i+1] < min_sum){
			   min_sum = current[i]+current[i+1];
			   index = i;
		   }
	   }
	   for(int i = 0 ; i < current.size(); i++){
		   if(i==index){
			   tmp.push_back(min_sum);
			   i++;
		   }else tmp.push_back(current[i]);
	   }
	   res++;
	   current = tmp;
	}
	return res;
    }
    int minimumPairRemoval(vector<int>& nums) {
	return solve(nums);
    }
};
/*
 Input: nums = [5,2,3,1]

     5 2 3 1
     (7,5,2), (5,2,3), (4,2,3)
     non-decreasingly, lowest sum is first pair
[2,2,-1,3,-2,2,1,1,1,0,-1] 
       1      0             
  2 2 -1 3 -2 2 1 1 1 0 -1
       1      0     0
  2 2 -1 3 -2 2 1 1 1 -1
       1         0 
  2 2 -1 3 0 1 1 1 -1
    1        1
  2 2 -1 3 0 1 1 0
        1   
  2 1 3 0 1 1 0

  2 1 3 1 1 0

  2 1 3 1 1

  2 1 3 2

  3 3 2





*/
