class Solution {
public:
    bool helper(string &st){
	 int n = st.size();
	 for(int i = 0; i+1 < n; i++){
		 if(st[i]=='+' && st[i+1] == '+'){
			 st[i]='-'; st[i+1]='-';
			 bool participant_zero_won = !helper(st);//keep fliping the result
			 st[i]='+'; st[i+1]='+';
			 if(participant_zero_won)return true;
		 }
	 }
	 return false;
    }
    bool solve(string &st){
	    return helper(st);
    }
    int firstMissingNumber(unordered_set<int> &lut){
	    int m = lut.size();
	    for(int i = 0 ; i < m; i++){
		    if(!lut.count(i)) return i;
	    }
	    return m;
    }
    bool solve2(string &st){
	    int curlen = 0, maxlen = 0;
	    vector<int> board_init_state;
	    for(int i = 0 ; i < st.size(); i++){ // get the max len of positive signs
		    if(st[i] == '+') curlen++;
		    if(i+1 == st.size() || st[i] == '-'){
			    if(curlen >=2) board_init_state.push_back(curlen);
			    maxlen = max(maxlen, curlen);
			    curlen = 0;
		    }
	    }
	    vector<int> g(maxlen+1, 0); // sprague-grundy function..
	    for(int len = 2; len <=maxlen; len++){
		    unordered_set<int> gsub;
		    for(int len_first_game = 0; len_first_game < len/2; len_first_game++){
			    int len_second_game = len-len_first_game - 2;
			    gsub.insert(g[len_first_game] ^ g[len_second_game]);
		    }
		    g[len] = firstMissingNumber(gsub);
	    }
	    int g_final = 0;
	    for(auto &s:board_init_state) g_final ^= g[s];
	    return g_final != 0;
    }
    bool canWin(string currentState) {
	    return solve2(currentState);
	    return solve(currentState);
    }
};
