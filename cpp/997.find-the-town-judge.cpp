class Solution {
public:
    //O(v+e)
    int solve(int n, vector<vector<int>>&t){
	vector<int> _in(n,0), _out(n,0);
	for(auto edge:t){//O(e)
	   _in[edge[1]-1]++;
	   _out[edge[0]-1]++;
	}
	vector<int> town_judge;
	for(int i = 0 ; i< n; i++){//O(n)
	   if(_in[i] == n-1 && _out[i] == 0)town_judge.push_back(i);
	}
	if(town_judge.size()==1) return town_judge.front()+1;
	return -1;
    }
    int findJudge(int n, vector<vector<int>>& trust) {
	return solve(n, trust);
    }
};
