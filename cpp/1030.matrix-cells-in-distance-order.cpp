class Solution {
public:
    vector<vector<int>> allCellsDistOrder(int rows, int cols, int rCenter, int cCenter) {
	    vector<tuple<int, int, int> > info;
	    for(int i = 0; i < rows; i++){
		    for(int j = 0; j < cols; j++){
			    info.push_back({abs(rCenter-i)+abs(cCenter-j), i,j});
		    }
	    }
	    sort(info.begin(), info.end());
	    vector<vector<int> > res;
	    for(auto [a,b,c]:info){
		    res.push_back({b,c});
	    }
	    return res;
    }
};
