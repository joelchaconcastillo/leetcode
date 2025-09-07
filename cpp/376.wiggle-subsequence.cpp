class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
         int n = nums.size(), res = 0;
	 if(n<=1)return 1;
	 int max_cont1=0, max_cont2=0;
	 for(int i = 1; i < n; i++){
		 int current = 0;
		 if(nums[i]-nums[i-1]<0) current=-1;
		 else if (nums[i]-nums[i-1]>0) current=1;
		 if(current == -1) max_cont1 = max(max_cont1, max_cont2+1);
		 if(current == 1) max_cont2 = max(max_cont2, max_cont1+1);
		 res = max(max_cont1+1, max_cont2+1);
	 }
	 return res;
    }
};
