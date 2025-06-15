class Solution {
public:
    int solve_optimized(int n){
	if(n==1)return 9;
	const long long MOD = 1337;
	long long hi = pow(10,n)-1;
	long long lo = pow(10,n-1);
	for(long long i = hi; i>=lo; i--){
	    string s = to_string(i);
	    string rev_s(s.rbegin(), s.rend());
	    long long palindrome = stoll(s+rev_s);
	    for(long long j = hi; j>=lo; j--){
		if(palindrome % j == 0){
		   long long other = palindrome/j;
		   if(other >=lo && other <=hi) return palindrome%MOD;
		}
	        if(j*j < palindrome) break;
	    }
	}
	return 0;
    }
    int solve(int n){
	if(n==1)return 9;
	long long res = 0;
	const long long MOD = 1337;
	long long hi = pow(10, n);
	long long lo = pow(10, n-1);
	for(long long i = hi-1; i>=lo; i--){//iterate on each "word"
	    string word = to_string(i);
	    string reversed_word = word; reverse(reversed_word.begin(), reversed_word.end());
	    long long ll_palindrome = stoll(word+reversed_word);
	    for(long long j = hi-1; j>=sqrtl(ll_palindrome); j--){//find a term that work for that palindrome atttemp
		   if( ll_palindrome%j ==0) return ll_palindrome%MOD;
	    }
	}
	return 0;
    }
    int largestPalindrome(int n) {
	return solve_optimized(n);
    }
};
