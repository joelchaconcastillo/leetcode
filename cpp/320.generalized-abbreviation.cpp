class Solution {
public:
    void backTrack(string &word, int i, int l, string &current, vector<string> &res){
	    if(i>word.size())return ;
	    if(l==0){
		    res.push_back(word);
		    return;
	    }
	    if(i == word.size()){
		    res.push_back(current);
		    return;
	    }

	    //transform it
	    if(current.empty() || (!current.empty() && !isdigit(current.back()))){
		    for(int j = 1; j <= word.size(); j++){
		      string prev_current = current;
		      current += to_string(j);
		      backTrack(word, i+j,j, current, res);
		      current = prev_current;
		    }
	    }
	    //skip it
	    current.push_back(word[i]);
	    backTrack(word, i+1, l, current, res);
	    current.pop_back();
    }
    vector<string> solve(string &word){
	    int n = word.size();
	    vector<string> res;
	    string current = "";
	    backTrack(word, 0, n, current, res);
	    return res;
    }
    void helper(string &word, int idx, string current, vector<string> &res, int j){
	    if(idx == word.size()){
		    if(j != 0) current += to_string(j);
		    res.push_back(current);
		    return;
	    }
	    string new_string = "";
	    if(j != 0) new_string = to_string(j);
	    helper(word, idx+1, current+new_string+word[idx], res, 0);
	    helper(word, idx+1, current, res, j+1);
    }
    vector<string> solve1(string &word){
	    vector<string> res;
	    string current = "";
	    helper(word, 0, current, res, 0);
	    return res;
    }
    vector<string> solve2(string &word){
	    int n = word.size();
	    vector<string> res;
	    for(int mask = 0; mask < (1<<n); mask++){
		    string current="";
		    int count =0;
		    for(int i = 0; i < n; i++){
			    if(mask &(1<<i)){
				    count++;
			    }else{
				    if(count!=0) current +=to_string(count);
				    current += word[i];
				    count=0;
			    }
		    }
		    if(count) current += to_string(count);
		    res.push_back(current);
	    }
	    return res;
    }
    vector<string> generateAbbreviations(string word) {
	    return solve2(word);
	    return solve1(word);
	    return solve(word);
    }
};
