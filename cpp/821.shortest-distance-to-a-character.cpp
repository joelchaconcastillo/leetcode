class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
	 int n = s.size();
         vector<int> res(n, INT_MAX); 
	 int last = -1;
	 for(int i = 0 ; i < n; i++){
		 if(s[i]==c)last=i;
		 if(last!=-1) res[i] = min(res[i], i-last);
	 }
	 last = -1;
	 for(int i = n-1; i>=0; i--){
		 if(s[i]==c)last=i;
		 if(last!=-1) res[i] = min(res[i], last-i);
	 }
	 return res;
    }
};
