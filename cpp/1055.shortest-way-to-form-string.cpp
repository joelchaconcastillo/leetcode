class Solution {
public:
    int solve2(string source, string target) {
	int n = source.size(), m = target.size();
	vector<vector<int> > next(n, vector<int> (270, -1));
	vector<int> current (270, -1);
	for(int i = n-1; i >= 0; i--){
		current[source[i]] = i;
		next[i] = current;
	}
	int res = 1, j=0;
	for(auto letter:target){
		if(next[0][letter]==-1) return -1;
		if(j == n || next[j][letter]==-1){
		   res++;
		   j=0;
		}
		j = next[j][letter]+1;
	}
	return res;
    }
    int solve(string source, string target) {
	 unordered_map<char, vector<int> > letterPos;
	 int n = target.size(), m = source.size();
         for(int i = 0 ; i < m; i ++){
		 letterPos[source[i]].push_back(i);
	 }
	 int res = 1;
	 for(int i = 0, j = -1; i < n; i++){
		 if(!letterPos.count(target[i]))return -1;
		 auto &pos = letterPos[target[i]];
		 auto idx = upper_bound(pos.begin(), pos.end(), j)-pos.begin();
		 if(idx == pos.size()){
			 res++;
			 j=pos[0];
		 }else{
			 j = pos[idx];
		 }
	 }
	 return res;
    }
    int shortestWay(string source, string target) {
	return solve2(source, target);
	return solve(source, target);
    }
};
