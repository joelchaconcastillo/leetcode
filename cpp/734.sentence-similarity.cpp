class Solution {
public:
   
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
	    int n = sentence1.size(), m = sentence2.size();
	    if(n != m) return false;
	    unordered_map<string, unordered_map<string, bool> > edges;
	    for(auto vec:similarPairs){
		    edges[vec[0]][vec[1]]=true;
		    edges[vec[1]][vec[0]]=true;
	    }
	    for(int i = 0 ; i <n; i++){
		    auto word1 = sentence1[i];
		    auto word2 = sentence2[i];
		    if(word1 == word2)continue;
		    if( !edges[word1][word2])return false;
	    }
	    return true;
    }
};
