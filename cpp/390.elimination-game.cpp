class Solution {
public:
    int helper(int head, int gap, int n, int direction){
	    if(n==1) return head;
	    if(direction == 1){
		    return helper(head+gap, gap<<1, n>>1, 1-direction);
	    }
	    if( n%2 == 1) return helper(head+gap, gap<<1, n>>1, 1-direction);
	    return helper(head, gap<<1, n>>1, 1-direction);
    }
    int lastRemaining(int n) {
	    return helper(1, 1, n, 1);
    }
};
// 1 :                1
// 2 : 1 2            2
// 3 : 2              2
// 4 : 2 4            2
// 5 : 2 4            2
// 6 : 4              4
// 7 : 4              4
// 8 : 2 6            6
// 9 : 6              6
// 10: 8              8
// 11: 8              8
// 12: 6              6
