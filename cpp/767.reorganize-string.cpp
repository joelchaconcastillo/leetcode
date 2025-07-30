class Solution {
public:
    string solve(string &st){
	    int n = st.size();
	    unordered_map<char, int> freq;
	    for(auto letter:st)freq[letter]++;
	    priority_queue<tuple<int, char> > pq;
	    for(auto [letter, count]:freq){
		    pq.push({count, letter});
	    }
	    string res = "";
	    while(!pq.empty()){
		    auto [count1, letter1] = pq.top(); pq.pop();
		    //vvvlo --> (1,v), res="vlvo"
		    if(res.empty()){
			    res+=letter1;
			    count1--;
			    if(count1) pq.push({count1, letter1});
			    continue;
		    }
		    if(letter1 == res.back()){
			    if(pq.empty()) return "";
			    auto [count2, letter2] = pq.top(); pq.pop();
			    res += letter2;
			    count2--;
			    pq.push({count1, letter1});
			    if(count2>0)
			    pq.push({count2,letter2});
		    }else{
			    count1--;
			    res +=letter1;
			    if(count1)
			    pq.push({count1, letter1});
		    }
	    }
	    return res;
    }
    string solve2(string &st){
	    unordered_map<char, int> freq;
	    int maxF=0;
	    char maxl=' ';
	    for(auto letter:st){
		    freq[letter]++;
		    if(freq[letter]>maxF){
			    maxF=freq[letter];
			    maxl=letter;
		    }
	    }
	    int n = st.size();
	    if(maxF > (n+1)/2)return "";
	    string res(n, ' ');
	    int i = 0;
	    for(; i < n && freq[maxl]>0; i+=2){
		    res[i] = maxl;
		    freq[maxl]--;
	    }
	    for(auto [l, c]:freq){
		    while(c>0){
		       if(i>=n)i=1;
		       res[i]=l;
		       i+=2;
		       c--;
		    }
	    }
	    return res;
    }
    string reorganizeString(string s) {
	    return solve2(s);
	    return solve(s);
    }
};
