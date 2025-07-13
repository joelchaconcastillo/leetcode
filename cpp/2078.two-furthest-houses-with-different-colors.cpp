class Solution {
public:
    int solve(vector<int> &colors){
	    int n = colors.size();
	    int res = 0;
	    for(int i = 0 ; i <n; i++){
		    int j = 0;
		    while(j<n && colors[i]==colors[j])j++;
		    res = max(res, abs(i-j));
	    }
	    return res;
    }
    int maxDistance(vector<int>& colors) {
	    return solve(colors);
    }
};
