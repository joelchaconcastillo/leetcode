class Solution {
public:
    string solve(vector<string> &words){
	   unordered_map<char, unordered_set<char> > adjList;
	   unordered_map<char, int> indeg;
	   for(auto word:words){
		   for(auto letter:word)indeg[letter]=0;
	   }

	   for(int i = 0 ; i+1 < words.size(); i++){
		   int _size=min(words[i].size(), words[i+1].size());
		   if(words[i].size() > words[i+1].size() && words[i].substr(0, _size) == words[i+1])return "";
		   for(int j = 0; j <_size; j++){
			   if(words[i][j]==words[i+1][j])continue;
			   if(adjList[words[i][j]].insert(words[i+1][j]).second)
				   indeg[words[i+1][j]]++;
			   break;
		   }
	   }

	   queue<char> q;
	   for(auto i:indeg){
		   if(i.second==0)q.push(i.first);
	   }
	   string path="";
	   while(!q.empty()){
		   auto current = q.front(); q.pop();
		   path+=current;
		   for(auto _to:adjList[current]){
			   indeg[_to]--;//remove edge
			   if(indeg[_to]==0) q.push(_to);
		   }
	   }
	   return path.size() == indeg.size()?path:"";
    }
    string alienOrder(vector<string>& words) {
	    return solve(words);
    }
};
