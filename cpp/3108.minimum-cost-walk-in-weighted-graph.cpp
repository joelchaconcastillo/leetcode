class Solution {
public:
    vector<int> p, r, score;
    int find(int u){
	return (p[u] == u )? u : ( p[u] = find(p[u]));
    }
    void _union(int u, int v, int _score){
	u = find(u), v = find(v);
	score[u] &= _score&score[v];
	if(u==v) return;
	if(r[u] < r[v]){
		swap(u,v);
		swap(score[u], score[v]);
	}
	p[v] = u;
	if(r[u]==r[v]) r[u]++;
    }
    vector<int> solve(int n, vector<vector<int>> &edges, vector<vector<int> > &query){
	    p.assign(n, 0);
	    r.assign(n, 0);
	    score.assign(n, (1<<30)-1);
	    for(int i = 0; i < n; i++)p[i] = i;
	    for(auto edge:edges){
		_union(edge[0],edge[1], edge[2]);
	    }
	    vector<int> res;
	    for(auto q:query){
		 int u = find(q[0]), v = find(q[1]);
		 if(u != v)res.push_back(-1);
		 else res.push_back(score[u]);
	    }
	    return res;
    }
    vector<int> minimumCost(int n, vector<vector<int>>& edges, vector<vector<int>>& query) {
	 return solve(n, edges, query);
    }
};
