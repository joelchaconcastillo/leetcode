class Solution {
public:
    int dist(string &A, string &B){
	    int total = 0;
	    for(int i = 0 ; i < A.size(); i++){
		    total += A[i]!=B[i];
	    }
	    return total;
    }	    

    int minMutation(string startGene, string endGene, vector<string>& bank) {
	    queue<string> q;
	    q.push(startGene);
	    unordered_set<string> visited;
	    int levels = 0;
	    while(!q.empty()){
		    int sz = q.size();
		    for(int i = 0 ; i < sz; i++){
		        auto current = q.front(); q.pop();
		        if(visited.count(current))continue;
		        visited.insert(current);
		        if(current==endGene)return levels;
		        for(auto _mutated:bank){
		          if(dist(current, _mutated) !=1)continue;
		          q.push(_mutated);
	                }
		    }
		    levels++;
	    }
	    return -1;
    }
};
