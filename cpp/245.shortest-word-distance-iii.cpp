class Solution {
public:
    int solve(vector<string> &wordsDict, string &word1, string &word2){
	    int n = wordsDict.size();
	    unordered_map<string, vector<int>> word2idx;
	    for(int i = 0 ; i < n; i++){
		    word2idx[wordsDict[i]].push_back(i);
	    }
	    int res = INT_MAX;
	    auto vec1 = word2idx[word1];
	    auto vec2 = word2idx[word2];
	    if(vec1.front()>vec2.front())swap(vec1, vec2);
	    int i = 0, j = 0;
	    while(i < vec1.size() && j < vec2.size()){
		    if(vec1[i]!=vec2[j]) res = min(res, abs(vec1[i]-vec2[j]));
		    if(vec1[i] < vec2[j]){
			    i++;
		    }else{
			    j++;
		    }
	    }
	    return res;
    }
    int solve2(vector<string> &wordsDict, string &word1, string &word2){
	    int n = wordsDict.size(), a=-n, b=n, res = INT_MAX;
	    for(int i = 0 ; i < n ;i++){
		    if(wordsDict[i] == word1){
			    if(word1==word2)b=a;
			    a = i;
		    }else if(wordsDict[i] == word2){
			    b = i;
		    }
		    res = min(res, abs(a-b));
	    }
	    return res;
    }
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
	    return solve2(wordsDict, word1, word2);
	    return solve(wordsDict, word1, word2);
    }
};
