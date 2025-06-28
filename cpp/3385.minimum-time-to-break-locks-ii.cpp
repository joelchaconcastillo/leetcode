class Solution {
public:
    int solve(vector<int> &str){
	    int n = str.size();
	    const int INF = 1e9;
	    //create cost matrix
	    vector<vector<int> > cost(n, vector<int>(n));
	    for(int i = 0 ; i < n; i++)
		    for(int j = 0 ; j < n; j++)
			    cost[i][j] = (str[i]+j)/(j+1);
	    //kuhn mukres algorithm with u,v a dual variables
	    //hungarian algorithm
	    vector<int> u(n+1), v(n+1), p(n+1), way(n+1);
	    for(int i=1; i<=n; i++){
		p[0] = i;
		vector<int> minv(n+1, INF);
		vector<bool>used(n+1, false);
		int j0=0;
		while(true){
		  used[j0]=true;
		  int i0 = p[j0], delta = INF, j1=-1;
		  for(int j = 1; j<=n; j++){
		     if(!used[j]){
			int cur = cost[i0-1][j-1]-u[i0]-v[j];
			if(cur < minv[j]) minv[j]=cur, way[j]=j0;
			if(minv[j] < delta) delta =minv[j], j1=j;
		     }
		  }
		  for(int j = 0; j <=n; j++){
		      if(used[j]){
			      u[p[j]] += delta;
			      v[j] -= delta;
		      }else minv[j] -= delta;
		  }
		  j0 = j1;
		  if(p[j0]==0)break;
		}
		//augmenting path
		do{
			int j1 = way[j0];
			p[j0] = p[j1];
			j0 = j1;
		}while(j0);
	    }
	    return -v[0];
    }
    int findMinimumTime(vector<int>& strength) {
	    return solve(strength);
    }
};
