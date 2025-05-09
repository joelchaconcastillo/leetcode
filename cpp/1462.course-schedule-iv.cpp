class Solution {
public:
    vector<bool> solve1(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>> & queries){
	    vector<vector<bool> > isReachable(numCourses, vector<bool> (numCourses, false));
	    for(auto e:prerequisites) isReachable[e[0]][e[1]]=true;
	    for(int k = 0 ; k < numCourses; k++){
		    for(int u = 0; u < numCourses; u++){
			    for(int v = 0; v < numCourses; v++){
				    isReachable[u][v] = isReachable[u][v] ||( isReachable[u][k] && isReachable[k][v]);
			    }
		    }
	    }
	    vector<bool> res(queries.size());
	    for(int i = 0 ; i < queries.size(); i++) res[i] = isReachable[queries[i][0]][queries[i][1]];
	    return res;
    }
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
	   return solve1(numCourses, prerequisites, queries);
    }
};
