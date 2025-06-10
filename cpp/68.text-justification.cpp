class Solution {
public:
    vector<string> solve(vector<string> &words, int maxWidth){
	    vector<vector<string> > matrix_words;
	    vector<string> last_row;
	    int cont=0;
	    for(auto word:words){
		if(cont+word.size() > maxWidth){
		   matrix_words.push_back(last_row);
		   last_row.clear();
		   cont=0;
		}
		last_row.push_back(word);
		cont+=word.size()+1;
	    }
	    if(!last_row.empty())matrix_words.push_back(last_row);
	    vector<string> res;
	    for(int k = 0 ; k+1 < matrix_words.size(); k++){
		 auto line = matrix_words[k];
		 int total_size=0;
		 for(auto word:line) total_size+=word.size();
		 while(total_size<maxWidth && line.size()>1){
		      for(int i = 0 ; i+1 < line.size(); i++){
			  line[i]+=" ";
			  total_size++;
			  if(total_size==maxWidth)break;
		      }
		 }
		 string tmp="";
		 for(auto &word:line) tmp+=word;
		 while(tmp.size() < maxWidth)tmp+=" ";
		 res.push_back(tmp);
	    }
	    string last = "";
	    for(auto word:matrix_words.back()){
		last += word+" ";
	    }
	    if(last.size() > maxWidth)last.pop_back();
	    while(last.size() < maxWidth) last+=" ";
	    res.push_back(last);
	    return res;
    }
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
	   return solve(words, maxWidth);
    }
};
