class Solution {
public:
    int backtracking(vector<int> &st, int k, int x, int level, vector<bool> &marked){
	 if(level == st.size()){
	    return 0;
	 }
	 int res = INT_MAX;
	 for(int i =  0; i < st.size(); i++){
	    if(marked[i])continue;
	    marked[i]=true; 
	    int current = backtracking(st, k, x+k, level+1, marked)+ceil(st[i]/(double)x); 
	    marked[i]=false; 
	    res = min(res, current);
	 }
	 return res;
    }
    int solve(vector<int> &strength, int k){
	vector<bool>marked((int)strength.size(), false);
	return backtracking(strength, k, 1, 0, marked);
    }
    int findMinimumTime(vector<int>& strength, int k) {
	return solve(strength, k);
    }
};
/*
 strength = [3,4,1], k = 1 : 4

   1 3 4
   1 2 2
   
   1 4 3
   1 2 1
   x: 3

 strength = [2,5,4], k = 2 : 5

 * */
