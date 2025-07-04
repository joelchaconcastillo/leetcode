class Solution {
public:
    int solve(int x){
	  int sum = 0, x_cpy=x;
	  while(x_cpy){
		  sum+=x_cpy%10;
		  x_cpy/=10;
	  }
	  if(x%sum==0)return sum;
	  return -1;
    }
    int sumOfTheDigitsOfHarshadNumber(int x) {
	    return solve(x);
    }
};
