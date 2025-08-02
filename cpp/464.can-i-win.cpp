class Solution {
public:
    unordered_map<int, int> memo;
    bool helper(int max_n, int total, int mask){
	    if(memo.count(mask))return memo[mask]==0;
	    for(int i = 0; i < max_n; i++){
		    if(mask&(1<<i))continue;
		    int minus = total-(i+1);
		    if(minus <= 0)return true;
		    if(!helper(max_n, minus, mask|(1<<i))){
			    memo[mask] = 0;
			    return true;
		    }
	    }
	    memo[mask] = 1;
	    return false;
    }
    bool solve(int maxChoosableInteger, int desiredTotal){
	    if(desiredTotal==0)return true;
	    if( maxChoosableInteger*(maxChoosableInteger+1)/2 < desiredTotal)return false;
	    return helper(maxChoosableInteger, desiredTotal, 0);
    }
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
	    return solve(maxChoosableInteger, desiredTotal);
    }
};
