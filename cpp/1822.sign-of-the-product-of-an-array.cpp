class Solution {
public:
    int arraySign(vector<int>& nums) {
       int res = 1;
       for(auto num:nums){
	       if(num<0)res*=-1;
	       else if(num==0)res=0;
       }
      return res; 
    }
};
