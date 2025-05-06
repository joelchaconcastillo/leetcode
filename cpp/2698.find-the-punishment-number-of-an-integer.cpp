class Solution {
public:
	//target square sum current 
	//10,    100,    0  0
	//
    bool isPunishment(int target, int square, int sum=0){
	 if(sum > target) return false;
	 if(square == 0){
	    return target==sum;
	 }
	 bool hasSol = false;
	 int powten=1;
	 while(square/powten){//9,1, 9,10
	     powten*=10;
	     int current = square%powten;
	     if(isPunishment(target, square/powten, sum+current)) return true;
	 }
	 return hasSol;
    }
    int solve(int n){
	int res = 0;
	for(int i = 1; i <=n; i++){
	   if(isPunishment(i, i*i)){
		   res+= i*i;
	   }
	}
	return res;
    }
    int punishmentNumber(int n) {
	return solve(n);
    }
};
/*
 
  100 --> 10
    i
  f(target, current)
 * */
