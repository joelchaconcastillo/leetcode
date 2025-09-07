class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
	for(int i = 0; i < 32; i++){
		vector<int>cont(2,0);
		for(auto num:nums) cont[(num>>i)&1]++;
		for(auto num:nums){
			int bit = (num>>i)&1;
			res += cont[1-bit];
			cont[bit]--;
		}
	}
        return res;	
    }
};
//       0100
//       1110
//       0010
//       1101
//       
// ones  1220
// zeros 2114
//       2220 --> 6
//
//         0 1 0
//   zeros 2 1 1
//   ones  1 1 0
//   
