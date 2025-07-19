class Solution {
public:
    vector<int> solve(vector<int> &nums){
	    int n = nums.size();
	    vector<long long> bits(32, 0);
	    for(auto num:nums){
		    for(long long i = 0; i <32 ;i++){
			    bits[i]  += (1LL<<i)&num;
		    }
	    }
	    long long dif = 0;
	    for(int i = 0 ; i < 32; i++) if(bits[i]%3) dif |= (1LL<<i);
	    long long pivot = dif & (-dif);
	    vector<long long> maskA(32,0), maskB(32, 0);
	    for(auto num:nums){
		    for(int i = 0 ;i < 32; i++){
			    if(num&pivot) maskA[i] += (num>>i)&1;
			    else maskB[i] += (num>>i)&1;
		    }
	    }
	    int valueA=0, valueB=0;
	    for(int i = 0 ; i < 32; i++){
		    if(maskA[i]%3)valueA |= (1LL<<i);
		    if(maskB[i]%3)valueB |= (1LL<<i);
	    }
	    for(int i = 0 ; i < 32; i++){
		    if(maskA[i]%3==1) return {valueA, valueB};
		    else if(maskA[i]%3==2) return {valueB, valueA};
	    }
	    return {-1};//not possible
    }
    vector<int> onceTwice(vector<int>& nums) {
	    return solve(nums);
    }
};
/*
 
 Input: nums = [2,2,3,2,5,5,5,7,7]
 Output: [3,7]
 2: 0 0 1 0
 3: 0 0 1 1
 5: 0 1 0 1
 7: 0 1 1 1
 ----------
    0 5 6 6
    0 2 0 0           
  
 * */
