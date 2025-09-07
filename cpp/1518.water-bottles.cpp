class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = 0, fill = numBottles, empty=0;
	while(fill){
		res += fill;
		empty += fill;
		fill = empty/numExchange;
		empty = empty%numExchange;
	}
	return res;
    }
};
