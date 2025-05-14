class Solution {
public:
    vector<int> p, r;
    void _union(int u, int v){
	 u = find(u);
	 v = find(v);
	 if( u == v) return;
	 if(r[u] < r[v]) swap(u,v);//v always min rank
	 p[v] = u;
	 if(r[u]==r[v]) r[u]++;// rank by max height
    }
    int find(int u){
	 return  u==p[u]?u:(p[u]=find(p[u]));
    }
    int solve_kruskal(vector<vector<int> >&points){
	   int n = points.size();
	   p.assign(n, 0);
	   r.assign(n, 0);
	   for(int i = 0 ; i < n; i++)p[i]=i;
	   typedef tuple<int, int, int> my_type;
	   priority_queue<my_type, vector<my_type>, greater<>> pq;
	   for(int i = 0; i < points.size(); i++){
	      for(int j = i+1; j < points.size(); j++){
		      pq.push({abs(points[i][0]-points[j][0])+abs(points[i][1]-points[j][1]), i, j});
	      }
	   }
	   int taken = 0, min_cost = 0;
	   while(!pq.empty() && taken < n){
		auto [w, u, v] = pq.top(); pq.pop();
		if( find(u) == find(v))continue;
		_union(u, v);
		min_cost += w;
		taken++;
	   }
	   return min_cost;
    }

    int solve_prim(vector<vector<int> > &points){
	 int n = points.size();
	 typedef tuple<int, int> my_type;
	 set<my_type> pq;
	 vector<bool>taken(n, false);
	 taken[0] = true;
	 for(int i = 1; i <n; i++){
		 int dist = abs(points[0][0]-points[i][0])+abs(points[0][1]-points[i][1]);
		 pq.insert({dist, i});
	 }
	 int counter = 0, min_cost = 0;
	 while(!pq.empty() && counter < n){
		 auto [w, u] = *pq.begin();
		 pq.erase(pq.begin());
		 if(taken[u])continue;
		 taken[u] = true;
		 min_cost +=w;
		 counter++;
		 for(int i = 0; i < n; i++){
			if(taken[i])continue;
		        int dist = abs(points[u][0]-points[i][0])+abs(points[u][1]-points[i][1]);
 		        pq.insert({dist, i});
		 }
	 }
	 return min_cost;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
	return solve_kruskal(points);
	return solve_prim(points);
    }
};
