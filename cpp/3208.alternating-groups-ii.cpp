class Solution {
public:
    int solve(vector<int>& colors, int k) {
	    int n = colors.size();
	    int l = 0, i = 1;
	    int prev = colors[0], res=0;
	    while( l < n ){
		    if(colors[i%n]==prev) l = i;
		    if(i-l+1>=k) res++, l++;
		    prev = colors[i%n];
		    i++;
	    }
	    return res;
    }
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
	    return solve(colors, k);
    }
};

//    0 1 0 0 1 0 1
//          l           
//          r
//
//    +1
//    +1
//    +1
//    +1
//    +1
//
//
//    k <=n
//
//
