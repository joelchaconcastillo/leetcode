class Solution {
public:
    bool fits_window(string &st, int k, int string_len){
	    unordered_map<char, int> freq;
	    int l = 0, maxf=0, n = st.size();
	    for(int i = 0 ; i < n; i++){
		    freq[st[i]]++;
		    if(i-l+1 > string_len){
			    freq[st[l++]]--;
		    }
		    maxf = max(freq[st[i]], maxf);
		    if(string_len-maxf <= k) return true;
	    }
	    return false;
    }
    // binary search 
    int solve1(string &st, int k){
	    int n = st.size();
	    int lo = 1, hi = n;
	    //look for the last 'yes' does it fit?
	    while(lo<hi){
		    int mid = (lo+hi)/2;
		    if(!fits_window(st, k, mid)){
			    hi = mid;
		    }else lo = mid+1;
	    }
	    if(!fits_window(st, k, lo))return lo-1;
	    return lo;
    }
    int solve1_1(string &st, int k){
	    int jump = st.size()/2, pivot=1, n = st.size();
	    for(;jump > 0; jump>>=1){
		    while(pivot+jump <= n && fits_window(st, k, pivot+jump)) pivot += jump;
	    }
	    return pivot;
    }
    int solve2(string &st, int k){
	    set<char> letters_set;
	    for(auto letter: st){
		    letters_set.insert(letter);
	    }
	    int maxLen = 0;
	    for(auto letter:letters_set){
		    int _left = 0, counter = 0;
		    for(int i = 0 ; i < st.size(); i++){
			    if(st[i]!=letter)counter++;
			    while(counter>k){
				    counter -= (letter!=st[_left++]);
			    }
			    maxLen = max(maxLen, i-_left+1);
		    }
	    }
	    return maxLen;
    }
    int solve3(string &st, int k){
	    int start = 0;
	    unordered_map<char, int> freq;
	    int maxFrequency = 0, longestSubLen = 0;
	    for(int _end = 0; _end < st.size(); _end++){
		    freq[st[_end]]++;
		    maxFrequency = max(maxFrequency, freq[st[_end]]);
		    bool valid =  (_end-start+1-maxFrequency <=k);//its valid if mismatches are <= k
		    if(!valid){
			    freq[st[start++]]--;
		    }
		    longestSubLen = _end - start +1;
	    }
	    return longestSubLen;
    }
    int characterReplacement(string s, int k) {
	    return solve3(s, k);
	    return solve2(s, k);//O(k*n), O(k)
	    return solve1_1(s, k);
	    return solve1(s, k);
    }
};
