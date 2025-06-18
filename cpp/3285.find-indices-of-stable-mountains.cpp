class Solution {
public:
    vector<int> solve(vector<int> &height, int threshold){
	    vector<int> res;
	    int prev = height[0];
	    for(int i = 1; i <height.size(); i++){
		    if(threshold<prev)res.push_back(i);
		    prev = height[i];
	    }
	    return res;
    }
    vector<int> stableMountains(vector<int>& height, int threshold) {
	    return solve(height, threshold);
    }
};
