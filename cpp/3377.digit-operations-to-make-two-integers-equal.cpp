class Solution {
public:
    bool isPrime(int n){
	 if(n<=1)return false;
	 if(n==2 || n==3)return true;
	 for(int i = 2; i*i <= n; i++){
	    if(n%i==0)return false;
	 }
	 return true;
    }
    vector<int> edges(int n){
	   vector<int> res;
	   string st = to_string(n);
	   for(int i = 0 ; i < st.size(); i++){
	       for(char j = st[i]-1; j <=st[i]+1; j++){
	          string _copy = st;
		  if(j == st[i])continue;
		  if(j<'0' || j>'9')continue;
		  _copy[i] = j;
		  res.push_back(stoi(_copy));
	       }
	   }
	   return res;
    }
    int solve(int n, int m){
	unordered_map<int, int> dist;
	string st_n = to_string(n), st_m = to_string(m);
	if(isPrime(n) || isPrime(m))return -1;
	typedef tuple<int, int> my_key;
	priority_queue<my_key, vector<my_key>, greater<>>pq;
        dist[n] = n;
	pq.push({n, n});
	while(!pq.empty()){
	     auto [wu, u] = pq.top(); pq.pop();
	     if(isPrime(u))continue;
	     if( m == u) return wu;
	     for(auto v:edges(u)){
		 int next_dist = dist[u]+v;
		 if(isPrime(v)) continue;
		 if(!dist.count(v))dist[v]=INT_MAX;
		 if(next_dist >= dist[v]) continue;
		 dist[v] = next_dist;
		 pq.push({next_dist, v});
	     }
	}
	if(!dist.count(m))return -1;
	return dist[m];
    }
    int minOperations(int n, int m) {
	return solve(n, m);
    }
};
