class Solution {
public:
 
    int solve(int target) {
	    target = abs(target);
	    long long step = 0, sum=0;
	    while(sum < target){
		    sum += ++step;
	    }
	    if((sum-target)%2==0){
		    return step;
	    }
	    return step+1+step%2;
    }
    int reachNumber(int target) {
	    return solve(target);
    }
};
