class Solution {
public:
    vector<vector<string> > res;
    bool isPalindrome(string &s, int l, int r){
	 while(l<=r){
	     if(s[l++]!=s[r--])return false;
	 }
	 return true;
    }
    void recursive(string &s, int i, vector<string> &path){
	 int n = s.size();
	 if(i==n){
	    res.push_back(path);
	    return;
	 }
	 for(int j = i; j < n; j++){
	    if(!isPalindrome(s, i,j))continue;
	    path.push_back(s.substr(i, j-i+1));
	    recursive(s, j+1, path);
	    path.pop_back();
	 }
    }
    vector<vector<string> > solve(string &s){
	 vector<string> path;
	 recursive(s, 0, path);
	 return res;
    }
    vector<vector<string>> partition(string s) {
        return solve(s);
    }
};
