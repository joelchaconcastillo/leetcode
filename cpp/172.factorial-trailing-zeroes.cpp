class Solution {
public:
	//3 x 2 x 1
	//  13 x 20 --> 260
    int solve(int n){
	if( n == 0 )return 0;
	int countZeros = 0; 
	long long current = 1;
	for(int i = 1; i <=n ; i++){
	   while(current%10==0 && current >=10 ) countZeros++, current/=10;
	   int ii=i;
	   while(ii%10==0 && ii >=10 ) countZeros++, ii/=10;
	   current%=100000;
	   ii%=100000;
	   current *=ii;
	}

	while(current%10==0 && current >=10)countZeros++, current/=10;
	return countZeros;
    }
    int trailingZeroes(int n) {
	return solve(n);
    }
};

/*
  10 40 --> 400
   A  x   B --->  C
   10^4   10^4   10^8
   10000  10000
 */
