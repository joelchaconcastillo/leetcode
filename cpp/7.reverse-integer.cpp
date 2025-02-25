class Solution {
public:
    /*
       time: O(n)
       space: O(1)
     * */
    int solve(int x){
       int res = 0;
       int sign = x<0?-1:1;
       while(x){
	   if(sign > 0 && INT_MAX/10 < res) return 0;
	   if(sign < 0 && INT_MIN/10 > res) return 0;
	   res *=10;
	   if(sign > 0 && INT_MAX-(x%10) < res)return 0;
	   if(sign < 0 && INT_MIN-(x%10) > res)return 0;
	   res += x%10;
	   x/=10;
       }
       return res;
    }
    int reverse(int x) {
       return solve(x);
    }
};
