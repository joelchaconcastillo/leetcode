class Solution {
public:
    string flip_row(string &st){
	    int n = st.size();
	    string res = "";
	    for(auto letter:st){
		    res += (letter=='1')?"0":"1";
	    }
	    return res;
    }
    int solve(vector<vector<int> > &matrix){
	    int n = matrix.size(), m = matrix[0].size();
	    int res = 0;
	    vector<string> string_matrix(n);
	    for(int i = 0 ; i < n; i++){
		    string row ="";
		    for(int j = 0 ; j < m; j++){
			    if(matrix[i][j])row+="1";
			    else row+="0";
		    }
		    string_matrix[i] = row;
	    }
	    unordered_map<string, int> counter;

	    for(auto row:string_matrix){
		    auto row_flipped = flip_row(row);
		    counter[row]++;
		    counter[row_flipped]++;
		    res = max(res, counter[row]);
		    res = max(res, counter[row_flipped]);
	    }
	    return res;
    }
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
	    return solve(matrix);
    }
};
