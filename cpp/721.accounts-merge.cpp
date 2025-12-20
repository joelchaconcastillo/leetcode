class Solution {
public:
    unordered_map<string, string> pa;
    unordered_map<string, int> rank;
    unordered_map<string, string> names;
    string _find(string a){
	    return (a!=pa[a])?(pa[a] =_find(pa[a])):a;
    }
    void _union(string a, string b){
	    a = _find(a);
	    b = _find(b);
	    if( a == b ) return;
	    if(rank[a] < rank[b])swap(a,b);
	    pa[b] = a;
    }
    vector<vector<string>> solve(vector<vector<string>>& accounts) {
	    for(auto &row:accounts){
		    for(int i = 1 ;i < row.size(); i++){
			    pa[row[i]] = row[i];
			    names[row[i]] = row[0];
			    rank[row[i]] = 1;
		    }
	    }
	    for(auto &row:accounts){
		    for(int i = 2; i < row.size(); i++){
			    _union(row[1], row[i]);
		    }
	    }
	    vector<vector<string> > res;
	    unordered_map<string, vector<string> > groups;
	    for(auto [email, pa_email]:pa){
		    groups[_find(email)].push_back(email);
	    }
	    for(auto [id, emails]:groups){
		    vector<string> row;
		    sort(emails.begin(), emails.end());
		    row.push_back(names[id]);
		    for(auto email:emails)row.push_back(email);
		    res.push_back(row);
	    }
	    return res;
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
	    return solve(accounts);
    }
};
