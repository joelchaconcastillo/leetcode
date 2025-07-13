class Solution {
public:
    int Solve(vector<vector<int> > &logs){
	    vector<int> deltas(3000);
	    for(auto log:logs){
		    deltas[log[0]]++;
		    deltas[log[1]]--;
	    }
	    for(int i = 1; i < deltas.size();i++){
		    deltas[i] += deltas[i-1];
	    }
	    int res = 0, maxc=0;
	    for(int i = 1950; i < deltas.size(); i++){
		    if(maxc < deltas[i]){
			    maxc=deltas[i];
			    res = i;
		    }
	    }
	    return res;
    }
    int maximumPopulation(vector<vector<int>>& logs) {
	    return Solve(logs);
    }
};
