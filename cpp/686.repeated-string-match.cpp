class Solution {
public:
    int solve(string &a, string &b){
	
	int n = a.size(), m = b.size();
	if(m == 0 || n == 0)return -1;
	vector<int> pi(m,0);
	for(int i =1,j=0; i < m; i++){
	    while(j > 0 && b[i] != b[j])j=pi[j-1];
	    if(b[i]==b[j])j++;
	    pi[i]=j;
	}
	string tmp = "";
	while(tmp.size() <= 2*max(n, m)) tmp+=a;
	int match = -1, res = 0;//n < m ,  n > m
	for(int i = 0, j = 0; i < tmp.size(); i++){
	    while(j > 0 && tmp[i] != b[j])j=pi[j-1];
	    if(tmp[i] == b[j]) j++;
	    if(j == m){
		 match = i;
		 break;
	    }
	}
	if(match == -1)return -1;
	return ceil((match+1.0)/n);
    }
    int repeatedStringMatch(string a, string b) {
       return solve(a, b);   
    }
};
/*
 
 Example 1:

 Input: a = "abcd", b = "cdabcdab"
 Output: 3
 Explanation: We return 3 because by repeating a three times "abcdabcdabcd", b is a substring of it.

_____________________
 Example 2:

 Input: a = "a", b = "aa"
 Output: 2


 * */
