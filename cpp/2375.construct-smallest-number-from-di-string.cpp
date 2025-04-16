class Solution {
public:
    string back_track(string &st, string &current, int idx, unordered_set<char> marked){
	   int n = st.size();
	   if(current.size() == n+1){
		  return current;
	   }
	   string res(n+1,'9');
	   for(char i = '1'; i <='9'; i++){
	      if( marked.count(i))continue;
	      if(!current.empty() && st[idx-1] == 'I' && current.back() > i)continue;
	      if(!current.empty() && st[idx-1] == 'D' && current.back() < i)continue;
	      marked.insert(i);
	      current.push_back(i);
	      auto attempt = back_track(st, current, idx+1, marked);
	      res = min(res, attempt);
	      current.pop_back();
	      marked.erase(i);
	   }
	   return res;
    }
    bool check(string &st, string &attempt){
	 for(int i = 0; i < st.size(); i++){
	    if(st[i] == 'I' && attempt[i] > attempt[i+1]) return false;
	    if(st[i] == 'D' && attempt[i] < attempt[i+1]) return false;
	 }
	 return true;
    }
    string solve1(string &st){
	int n = st.size();
	string res(n+1,' ');
	string ans(n+1, '9');
	for(int i =  0 ; i <= n; i++) res[i] = '1'+i;
	do{
	  if(!check(st, res))continue;
	  if(res < ans) ans = res;	
	}while(next_permutation(res.begin(), res.end()));
	return ans;
    }
    string solve2(string &pattern){
	   string current = "";
	   unordered_set<char> marked;
	   return back_track(pattern, current, 0, marked);
    }
    string solve3(string &pattern){

    }
    string smallestNumber(string pattern) {
       //return solve1(pattern);	    
       //return solve2(pattern);	    
       return solve3(pattern);	    
    }
};
/*
 *                  
  O(n!*n)
  Input: pattern = "IIIDIDDD"
  Output: "123549876"
 *
 * */
