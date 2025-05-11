class Solution {
public:
    vector<vector<int> > solve(vector<vector<int> > & isWater){
	   int n =  isWater.size(), m = isWater[0].size();
	   queue<tuple<int, int, int>>q;
	   for(int i = 0 ; i < n; i++){
	      for(int j = 0 ; j < m; j++){
		      if(isWater[i][j]==1) q.push({i,j,0});
		      isWater[i][j]=-1;
	      }
	   }
	   vector<tuple<int, int>> directions = {
		   {0,-1}, {1,0}, {0,1}, {-1,0}};
	   while(!q.empty()){
		auto [r,c,s] = q.front(); q.pop();
		if(isWater[r][c]!=-1)continue;
		isWater[r][c] = s;
		for(auto [delta_r, delta_c]:directions){
			int next_r = r+delta_r, next_c = c+delta_c;
			if(next_r<0 || next_r >=n)continue;
			if(next_c<0 || next_c >=m)continue;
		        if(isWater[next_r][next_c]!=-1) continue;
			q.push({next_r, next_c, s+1});
		}
	   }
	   return isWater;
    }
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
	 return solve(isWater);
    }
};
