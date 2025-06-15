class Solution {
public:
    // time: O(e+v log(v))
    vector<long long> solve(vector<int> &regular, vector<int> &express, int expressCost){
	    typedef tuple<long long, int, int> my_type;//dist, node, regular/express
	    priority_queue<my_type, vector<my_type>, greater<>>pq;
	    int n = regular.size();
	    vector<vector<long long> > dist(n+1, vector<long long> (2, LLONG_MAX));
	    pq.push({0, 0, 0});
	    pq.push({expressCost, 0, 1});
	    while(!pq.empty()){
		    auto [current_dist, node, _type] = pq.top(); pq.pop();
		    if(current_dist > dist[node][_type])continue;
		    if(node==n)continue;
		    if(_type == 0){
			long long cost1 = current_dist+regular[node];
		        long long cost2 = current_dist+express[node]+expressCost;
		       if(cost1 < dist[node+1][0]){
			       dist[node+1][0] = cost1;
		               pq.push({cost1, node+1, 0});
		       }
		       if(cost2 < dist[node+1][1]){
			       dist[node+1][1] = cost2;
		               pq.push({cost2, node+1, 1});
		       }
		    }
		    if(_type == 1){
		       long long cost3 = current_dist+express[node];
		       long long cost4 = current_dist+regular[node];
		       if(cost3 < dist[node+1][1]){
			       dist[node+1][1] = cost3;
		               pq.push({cost3, node+1, 1});
		       }
		       if(cost4 < dist[node+1][0]){
			       dist[node+1][0] = cost4;
		               pq.push({cost4, node+1, 0});
		       }
		    }
	    }
	    vector<long long> res;
	    for(int i = 1; i <= n; i++){
		 res.push_back(min(dist[i][0], dist[i][1]));
	    }
	    return res;
    }
    long long dp(vector<int> &regular, vector<int> &express, int expressCost, int n, int type, vector<vector<long long > > &memo){
	    if(n<0){
		    return 0;
	    }
	    if(memo[n][type]!=-1)return memo[n][type];
	    long long res = INT_MAX;
	    if(type==0){
		 res = min(dp(regular, express, expressCost, n-1, type, memo)+regular[n], 
				 dp(regular, express, expressCost, n-1, 1-type, memo)+expressCost+express[n]);
	    }
	    if(type==1){
		 res = min(dp(regular, express, expressCost, n-1, type, memo)+express[n],
				 dp(regular, express, expressCost, n-1, 1-type, memo)+regular[n]);
	    }
	    return memo[n][type] = res;
    }
    vector<long long> solve_dp(vector<int> &regular, vector<int> &express, int expressCost){
	    int n = regular.size();
	    vector<vector<long long> > memo(n+1, vector<long long> (2,-1));
	    dp(regular, express, expressCost, express.size()-1, 0, memo);
	    vector<long long>res;
	    for(int i = 0; i<n;i++)res.push_back(memo[i][0]);
	    return res;
    }
    vector<long long> minimumCosts(vector<int>& regular, vector<int>& express, int expressCost) {
	    return solve_dp(regular, express, expressCost);
	    return solve(regular, express, expressCost);
    }
};
