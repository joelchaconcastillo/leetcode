class Solution {
public:
    vector<vector<int> > solve(vector<vector<int> > &people){
	    int n = people.size();
	    sort(people.begin(), people.end(), [&](vector<int> &a, vector<int> &b){
			    return make_pair(a[0], -a[1]) < make_pair(b[0], -b[1]);
			    });
	    vector<vector<int> > res(n, vector<int>(2,-1));
	    for(int i =  0 ;i  <n ;i++){
		    int j = 0, cont = 0;
		    while(res[j][1]!=-1)j++;
		    while(cont<people[i][1]){
			    j++;
			    cont += res[j][1]==-1;
		    }
		    res[j] = people[i];
	    }
	    return res;
    }
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
	    return solve(people);
    }
};
//   [[7,0],[4,4],[7,1],[5,0],[6,1],[5,2]]
//
//   [4,4] [5,0] [5,2] [6,1] [7,0] [7,1]
//   [4,4] [5,2] [5,0] [6,1] [7,1] [7,0]
//   [5,0] [7,0] [5,2] [6,1] [4,4] [7,1]
//  
//   if p[i][1] < rem_right:
//      on left
//
//
//   [5,0] [7,0] [7,1], [6,1] [5,2] [4,4]
//
//   [5,0] [7,0] [5,2] [6,1] [7,1], 
//
//
//   [5,0], [7,0], [5,2], [6,1], [4,4], [7,1]
//  [[7,0],[7,1]]
//        [6,1], [5,0]  [5,2]  [4,4]
//
//
