class Solution {
public:
    int solve(vector<int> &players, vector<int> &trainers){
	    sort(players.begin(), players.end());
	    sort(trainers.begin(), trainers.end());
	    int n = players.size(), m = trainers.size();
	    int i = 0, j =0, res = 0;
	    while(i < n && j < m){
		    if(players[i] > trainers[j])j++;
		    else{
			    res++;
			    i++;
			    j++;
		    }
	    }
	    return res;
    }
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) {
	    return solve(players, trainers);
    }
};
