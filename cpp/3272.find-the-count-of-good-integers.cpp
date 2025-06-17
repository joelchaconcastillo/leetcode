class Solution {
public:
    long long factorial(int n){
	 static vector<long long> factorials;
	 if(!factorials.empty())return factorials[n];
	 long long factorial = 1;
	 for(long long i = 1; i < 20; i++){
		 factorials.push_back(factorial);
		 factorial*=i;
	 }
	 return factorials[n];
    }
   long long count_valid_permutations(const string &st){
	   int n = st.size();
	   vector<int> freq(10,0);
	   for(auto digit:st)freq[digit-'0']++;
	   long long total = factorial(n);
	   for(auto f:freq) total /=factorial(f);//remove repeated items
	   if(freq[0] > 0){
		   freq[0]--;// fix one '0' at the beginning, so this freq is removed
		   long long zero_leading = factorial(st.size()-1);// get the number of permutations fixing 0 as an start
		   for(auto f:freq) zero_leading /=factorial(f);//this is to remove repeated digits after fixing first as '0'
		   total -= zero_leading;
	   }
	   return total;
   } 
   string get_digit_signature(string st){
	   sort(st.begin(), st.end());
	   return st;
   }
   long long solve(int n, int k){
	    if(n==1){
		 long long cont = 0;
		 for(int i =1; i<=9; i++){
			 if(i%k==0)cont++;
		 }
		 return cont;
	    }
	    int z = n/2;
	    long long lo = pow(10, z-1);// 10 < n=2, z=1  10-100
	    long long  hi = pow(10, z)-1;
	    long long cont = 0;
	    unordered_set<string> seen;
	    for(long long i = lo; i <= hi; i++){
		    string first_half = to_string(i), second_half=to_string(i);
		    if(first_half.front()=='0')continue;
		    reverse(second_half.begin(), second_half.end());
		    if(n%2==1){
		       for(char d='0'; d<='9'; d++){
		          string palindrome = first_half+d+second_half;
		          long long palindrome_l = stoll(palindrome);
		          if(palindrome_l % k != 0) continue;
			  string signature = get_digit_signature(palindrome);
			  if(seen.count(signature))continue;
			  seen.insert(signature);
			  cont += count_valid_permutations(palindrome);
		       }
		    }else{
		       string palindrome = first_half+second_half;
		       long long palindrome_l = stoll(palindrome);
		       if(palindrome_l % k != 0) continue;
		       string signature = get_digit_signature(palindrome);
		       if(seen.count(signature))continue;
		       seen.insert(signature);
		       cont += count_valid_permutations(palindrome);
		    }
	    }
	    return cont;
    }
    long long countGoodIntegers(int n, int k) {
	    return solve(n, k);
    }
};
/*
  
     Problem statement:
     return the count of good integer containing 'n' digits
     count all integers with 'n' digits that are divisible 'k'

     01234 | 56789
     [10000 - 99999]
     ( 1000000001 % k ) == 0
     (2x10^5)

     n=1,k=4
     0,4,8
     11 11

     

 * */
