class Solution {
public:
    int solve(vector<int> &height){
	int n = height.size(), i = 0, j = n-1, res = 0;

	while(i < j){
	   res = max(res, min(height[j],height[i])*(j-i));
	   if( height[i] < height[j]) i++;
	   else j--;
	}
	return res;
    }
    int maxArea(vector<int>& height) {
	return solve(height);
    }
};
