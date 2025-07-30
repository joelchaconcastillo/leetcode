class Solution {
public:
    int solve(vector<int> &nums){
	    int n = nums.size();
	    unordered_map<int, int > tab;
	    for(int i = 0 ; i <n ; i++){
		    for(int j =i+1 ; j < n ; j++){
			    tab[nums[i]*nums[j]]++;
		    }
	    }
	    int res = 0;
	    for(auto [prod, sum]:tab){
		    if(sum<=1)continue;
		    // (a,b), (c,d):
		    //               (a,b) (c,d)
		    //               (b,a) (c,d)
		    // (a,b) (d,c) (e,f) (k,l)
		    // 2: 1
		    // 3: 3
		    // 4: 6
		    res += 8*(sum*(sum-1))/2;//2*(l*(l+1))/2;
	    }
	    return res;
	    //   [2,3,4,6]
	    //    i
	    //      j      6
	    //        A B C
	    //        A,B  A,C
	    //        B,A, B,C 
	    //        C,A  C,B
	    //        3*4/2 = 6
	    //   6, (2,3),
	    //   8, (2,4)
	    //   12 (2,6), (3,4)
	    //   18 (3,6)
	    //   24 (4,6)
    }
    int tupleSameProduct(vector<int>& nums) {
       return solve(nums);	    
    }
};
