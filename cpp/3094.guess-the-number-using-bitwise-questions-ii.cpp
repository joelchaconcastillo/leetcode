/** 
 * Definition of commonBits API.
 * int commonBits(int num);
 */

class Solution {
public:
    int findNumber() {
        int res = 0, common = commonBits(0);
	commonBits(0);
	for(int i = 0 ; i < 30; i++){
		int attempt = res|(1<<i);
		int cnt = commonBits(attempt);
		if(cnt > common){
			res |= (1<<i);
			common = cnt;
		}
		commonBits(attempt);
	}
	return res;
    }
};
