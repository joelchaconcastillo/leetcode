class Solution {
public:
    vector<int> solve1(int n, vector<vector<int> > &edges, vector<vector<int> > &query){
	  vector<vector<int> > adjList(n);
	  for(auto e:edges){
		 adjList[e[0]].push_back(e[1]);
		 adjList[e[1]].push_back(e[0]);
	  }
	  vector<vector<long long> > dists(n, vector<long long>(n, INT_MAX));
	  for(int i = 0 ; i < n; i++){
	       int depth = 0;
	       queue<int> q; q.push(i);
	       vector<bool> visited(n, false);
	       while(!q.empty()){
		    queue<int> tmp;
		    while(!q.empty()){
		            auto current = q.front();q.pop();
			    if(visited[current])continue;
			    visited[current]=true;
         		    dists[i][current] = dists[current][i] = depth;
         		    for(auto _to:adjList[current]){
         			tmp.push(_to);
         		    }
		    }
		    depth++;
		    q=tmp;
	       }
	  }
	  vector<int> res;
	  for(auto _quey: query){
	      int a = _quey[0], b = _quey[1], target = _quey[2];
	      long long min_dist = INT_MAX, idx=0;
	      for(int i = 0; i < n; i++){
		   if(min_dist > dists[i][a]+dists[i][b]+dists[i][target]){
		      min_dist = dists[i][a]+dists[i][b]+dists[i][target];
		      idx=i;
		   }
	      }
	      res.push_back(idx);
	  }
	  return res;
    }
    void dfs(vector<vector<int> > &edges, int current, int parent, vector<int> &parents, vector<int> &depth, int level){
	 parents[current] = parent;
	 depth[current] = level;
	 for(auto _to:edges[current]){
		 if(_to==parent)continue;
		 dfs(edges, _to, current,  parents, depth, level+1);
	 }
    }
    int lca(int a, int b, vector<int> &parents, vector<int> &depth){
	    int startA = a, startB = b;
	    while(depth[a] > depth[b])a=parents[a];
	    while(depth[b] > depth[a])b=parents[b];
	    while(a!=b){
		  a = parents[a];
		  b = parents[b];
	    }
	    return a;
    }
    vector<int> solve2(int n, vector<vector<int> > &edges, vector<vector<int> > &query){
	  vector<vector<int> > adjList(n);
	  for(auto e:edges){
		 adjList[e[0]].push_back(e[1]);
		 adjList[e[1]].push_back(e[0]);
	  }
	  vector<int> parents(n), depth(n, 0);
	  dfs(adjList, 0, 0, parents, depth, 0);
	  vector<int> res;
	  for(auto q:query){
	      int a = q[0], b = q[1], c = q[2];
	      int lca1 = lca(a, b, parents, depth);
	      int lca2 = lca(a, c, parents, depth);
	      int lca3 = lca(b, c, parents, depth);
	      int ans = lca1;
	      if(depth[lca2]>depth[ans]) ans=lca2;
	      if(depth[lca3]>depth[ans]) ans=lca3;
	      res.push_back(ans);
	  }
	  return res;
    }
    vector<int> closestNode(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
//       return solve1(n, edges, query);
       return solve2(n, edges, query);
    }
};
