class Solution {
public:
    unordered_map<char, int>freq;
    int dist(){
	  return abs(freq['S']-freq['N'])+abs(freq['W']-freq['E']);
    }	    
    /*
     * time: O(n)
     * space: O(1)
     * */
    int maxDistance(string s, int k) {
	    int res = 0, n = s.size();
	    for(int i = 0 ; i< n; i++){
		    freq[s[i]]++;
		    res = max(res, dist()+ min(i+1-dist(), 2*k));
	    }
	    return res;
    }
};
/*

   NSWWEW

    xxxxxx
         0

*/
