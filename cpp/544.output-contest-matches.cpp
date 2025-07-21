class Solution {
public:
    string solve(int n){
	   vector<string> competitions;
	   for(int i = 1; i <=n; i++) competitions.push_back(to_string(i));
	   while(competitions.size() >1){
		 vector<string> tmp;
		 int l = 0, r = competitions.size()-1;
		 while(l<r){
		      string pairing = "("+competitions[l]+","+competitions[r]+")";
		      tmp.push_back(pairing);
		      l++, r--;
		 }
		 competitions = tmp;
	   }
	   return competitions.front();
    }
    string findContestMatch(int n) {
	    return solve(n);
    }
};
