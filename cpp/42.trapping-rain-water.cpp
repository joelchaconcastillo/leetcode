class Solution {
public:
   int solve3(vector<int> &h){
       int n = h.size();
       int l = 0, r = n-1, res = 0;
       while(l<r){
	  if(h[l] < h[r]){
	  }else{

	  }
       }
       return res;
   }
   int solve2(vector<int> &h){
       int n = h.size();
       vector<int> dp1(n,0), dp2(n,0);
       dp1[0] = h[0];
       dp2.back() = h.back();
       for(int i = 1 ; i < n; i++) dp1[i] = max(dp1[i-1], h[i]);
       for(int i = n-2 ; i >= 0; i--) dp2[i] = max(dp2[i+1], h[i]);
       int res = 0;
       for(int i = 0 ;i < n; i++){
	   int minh = min(dp1[i], dp2[i]);
	   res += max(0, minh-h[i]);
       }
       return res;
   }
   int solve1(vector<int> &h){
     long long area2Right = 0, area2Left =0, totalArea= 0, maxhR=0, maxhL=0, n = h.size();
    for(int i =  0; i < n; i++){
          maxhR = max(maxhR, (long long)h[i]);
          maxhL = max(maxhL, (long long) h[n-i-1]);
          area2Right += maxhR;
          area2Left += maxhL;
         totalArea += h[i];
     }
   return   area2Right+area2Left-((long long)maxhL*n)-totalArea;
   }
    int trap(vector<int>& height) {
       return solve2(height);   
       return solve1(height);   
    }
};
