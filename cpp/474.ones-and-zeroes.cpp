class Solution {
public:
    unordered_map<int, unordered_map<int, unordered_map<int, int >> > memo;
    int dfs(vector<string> &strs, vector<int> &zeros, vector<int> &ones, int idx, int m, int n){
	    if(m < 0 || n< 0)return INT_MIN;
	    if(idx==strs.size()) return 0;
	    if(memo.count(idx) && memo[idx].count(m) && memo[idx][m].count(n))return memo[idx][m][n];
	    int res = 0;
	    res = max(
			    dfs(strs, zeros, ones, idx+1, m, n),
			    dfs(strs, zeros, ones, idx+1, m-zeros[idx], n-ones[idx])+1
			    );
	    return memo[idx][m][n] = res;
    }
    int findMaxForm(vector<string>& strs, int m, int n) {
	    int _sz = strs.size();
	    vector<int> ones, zeros;
	    for(auto &str:strs){
		    int contZeros=0, contOnes=0;
		    for(auto letter:str){
			    if(letter == '0')contZeros++;
			    else contOnes++;
		    }
		    ones.push_back(contOnes);
		    zeros.push_back(contZeros);
	    }
	    return dfs(strs, zeros, ones, 0, m, n);
    }
};
//  Input: strs = ["10","0001","111001","1","0"], m = 5, n = 3]
//  111001 
//  Output: 4
//
//
//    dfs(i, n, m) = max(
//                    dfs(i+1, n, m),
//                    dfs(i+1, n-ones[i], m-zeros[i])+1
//                    )
//
