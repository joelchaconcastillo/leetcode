class Solution {
public:
    int countBalls(int lowLimit, int highLimit) {
	   unordered_map<int, int>freq;
	   int res = 0;
	   for(int i = lowLimit; i<=highLimit; i++){
		   auto tmp = i;
		   int sum=0;
		   while(tmp){
			   sum+=(tmp%10);
			   tmp /=10;
		   }
		   freq[sum]++;
		   res = max(res, freq[sum]);
	   } 
	   return res;
    }
};
