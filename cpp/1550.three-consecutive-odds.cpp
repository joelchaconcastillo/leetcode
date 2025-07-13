class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
	    int n = arr.size();
         for(int i = 0; i < n; i++){
		 int cnt= 0 ;
		 for(int j = i; j < min(n, i+3); j++){
			 cnt += arr[j]%2;
		 }
		 if(cnt==3)return true;
	 }		 
	 return false;
    }
};
