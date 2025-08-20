class Solution {
public:
    int minJumps(vector<int>& arr) {
	int n = arr.size();
	unordered_map<int, vector<int> > num2indexes;
	for(int i = 0 ;i < n ;i++){
		num2indexes[arr[i]].push_back(i);
	}
	queue<int> q;
	unordered_set<int> visited;
	vector<int> dists(n, INT_MAX);
	q.push(0);
	dists[0]=0;
	while(!q.empty()){
		auto node = q.front(); q.pop();
		if(node==n-1)return dists[n-1];
	        int next_dist = dists[node]+1;
		if(node+1<n && dists[node+1] > next_dist){
			dists[node+1]=next_dist;
			if(node+1==n-1)return next_dist;
			q.push(node+1);
		}
		if(node-1>=0 && dists[node-1] > next_dist){
			dists[node-1]=next_dist;
			if(node-1==n-1)return next_dist;
			q.push(node-1);
		}
		for(auto j : num2indexes[arr[node]]){
			if(dists[j] <= next_dist) continue;
			if(j==n-1)return next_dist;
			dists[j]=next_dist;
			q.push(j);
		}
		num2indexes[arr[node]].clear();
	}
	return dists[n-1];
    }
};
