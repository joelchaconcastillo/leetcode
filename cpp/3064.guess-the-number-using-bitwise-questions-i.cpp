/** 
 * Definition of commonSetBits API.
 * int commonSetBits(int num);
 */

class Solution {
public:
    int findNumber() {
	int res = 0;
	for(int i = 0; i <32; i++){//0 0 0 1
		int attempt = (res|(1<<i));
		if(commonSetBits(attempt) > __builtin_popcount(res)) res = attempt;
	}
	return res;
    }
};
