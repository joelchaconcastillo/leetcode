class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<long long, int> freq;
	for(auto row:wall){
		long long sum = 0;
		for(int i = 0 ; i+1 < row.size(); i++){
			int col = row[i];
			sum+=col;
		       	freq[sum]++;
		}
	}
	int res = INT_MAX, n = wall.size();
	for(auto [edge, cont]:freq){
		res = min(res, n-cont);
	}
	if(res==INT_MAX)return n;
	return res;
    }
};
//wall = 
//    dp[
//       1: 0
//       3: 0
//       5: 0
//       6: 0
//       [1,2,2,1],
//       [3,1,2],
//       [1,3,2],
//       [2,4],
//       [3,1,2],
//       [1,3,1,1]
//    ]
