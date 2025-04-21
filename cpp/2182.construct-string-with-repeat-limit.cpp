class Solution {
public:
    string solve1(string s, int repeatLimit){
	    unordered_map<char, int> freq;
	    for(auto i:s)freq[i]++;
	    priority_queue<tuple<char, int>> pq;
	    for(auto ii:freq)pq.push(ii);
	    string res = "";
	    int counter = 0;
	    while(!pq.empty()){
		  auto [letter, cont] = pq.top(); pq.pop();
		  if(res.empty()){
			res += letter;
			counter=1;
			cont--;
			if(cont) pq.push({letter, cont});
			continue;
		  }
		  else if(res.back() != letter){
			counter=1;
			res+=letter;
			cont--;
			if(cont) pq.push({letter, cont});
			continue;
		  }
		  else if(res.back() == letter && counter < repeatLimit){
			counter++;
			res+=letter;
			cont--;
			if(cont) pq.push({letter, cont});
			continue;
		  }
		  if(pq.empty())break;
		  auto [letter2, cont2] = pq.top(); pq.pop();
		  counter=1;
		  res+=letter2;
		  cont2--;
		  if(cont2)
		  pq.push({letter2, cont2});
		  pq.push({letter, cont});
	    }
	    return res;

    }
    string solve2(string s, int repeatLimit){
	   string res = "";
	   vector<int> freq(26,0);
	   for(auto i:s)freq[i-'a']++;
	   int current_index = 25;
	   while(current_index >=0){
		 if(freq[current_index] == 0){
			 current_index--;
			 continue;
		 }
		 int rep = min(repeatLimit, freq[current_index]);
		 freq[current_index] -= rep;
		 string repeated(rep, current_index+'a');
		 res += repeated;
		 if(freq[current_index] > 0){
			int next_smaller = current_index-1;
			while(next_smaller>=0 && freq[next_smaller]==0)next_smaller--;
			if(next_smaller<0)break;
			res += char(next_smaller+'a');
			freq[next_smaller]--;
		 }
	   }
	   return res;
    }
    string solve3(string s, int repeatLimit){
	    unordered_map<char, int> freq;
	    for(auto i:s)freq[i]++;
	    priority_queue<char> pq;
	    for(auto ii:freq)pq.push(ii.first);
	    string res = "";
	    int counter = 0;
	    while(!pq.empty()){
		  auto letter = pq.top(); pq.pop();
		  int rep =min(repeatLimit, freq[letter]);
		  string repeated(rep, letter);
		  res += repeated;
		  freq[letter]-=rep;
		  if(freq[letter]){
		      if(pq.empty()) break;
		      auto letter2 = pq.top(); pq.pop();
		      res += letter2;
		      freq[letter2]--;
		      if(freq[letter2])pq.push(letter2);
		  }
		  if(freq[letter]) pq.push(letter);
	    }
	    return res;
    }
    string repeatLimitedString(string s, int repeatLimit) {
//	    return solve1(s, repeatLimit);
//	    return solve2(s, repeatLimit);
	    return solve3(s, repeatLimit);
    }
};
/*
 
Input: s = "cczazcc", repeatLimit = 3
Output: "zzcccac"
 a:0
 c:0
 z:0
 zzcccac


Input: s = "aababab", repeatLimit = 2
Output: "bbabaa"
  a:3
  b:2
  repeated 1
  b b a 
   
* */
