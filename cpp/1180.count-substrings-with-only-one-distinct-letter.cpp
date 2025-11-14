class Solution {
public:
    int countLetters(string s) {
        int n = s.size();
	int res = 0, l=0;
	char last = s[0];
	for(int i = 0 ; i < n; i++){
		if( s[i]!=last){
		    res += (i-l)*(i-l+1)/2;
		    l=i;
		}
		last = s[i];
	}
	res += (n-l)*(n-l+1)/2;
	return res;
    }
};
