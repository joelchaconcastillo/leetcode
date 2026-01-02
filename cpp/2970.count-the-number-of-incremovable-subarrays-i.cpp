class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int n  = nums.size();
	vector<vector<bool> > isIncremental(n+1, vector<bool>(n+1, false));
	for(int i = 0 ; i < n; i++){
		bool inc = true;
		int prev = INT_MIN;
		for(int j = i; j <n; j++){
			if(prev >=nums[j]) inc=false;
			isIncremental[i][j] = inc;
			prev = nums[j];
		}
	}
	int res = 0;
	for(int i = 0 ; i < n; i++){
		for(int j = i; j < n; j++){
			if(i>0 && j+1 < n && isIncremental[0][i-1] && isIncremental[j+1][n-1] && nums[i-1] < nums[j+1]) res++;
			else if(i == 0 && j+1 < n && isIncremental[j+1][n-1]) res++;
			else if( j+1 == n && i>0 && isIncremental[0][i-1])res++;
		}
	}
	return res+1; // +1 considering the empty one!
    }
};
