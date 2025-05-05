class Solution {
public:
    string res = "";
    // a, n:0, k:2
    // b, n:0, k:1
    // c, n:1, k:1
    void permutations(int n, int &k, string &st){
	 if(k<=0) return;
	 if(n==0){
	    if(k==1) res=st;
	    k--;
	    return;
	 }
	 for( char i='a'; i<='c'; i++){
	    if((!st.empty() && st.back() != i)||st.empty()){
	      st.push_back(i);
	      permutations(n-1, k, st);
	      st.pop_back();
	    }
	 }
    }
    string solve(int n, int k){
	   string current = "";
	   res = "";
	   permutations(n, k, current);
	   return res;
    }
    string getHappyString(int n, int k) {
	 return solve(n, k);
    }
};
/*
   n, k  
   1 --> a,b,c          :3
   2 --> ab, ac, ba, bc, ca, cb,    :6
   3 --> aba, abc, aca, acb, bab, bac, bca, bcb, cab, cac, cba, cbc :  12
   k > 
   2^(i-1)*3
   2^(9)*3-->1024*3-->3
   3, 6, 12
   3,6,12,24
    3,6, 12
 * */
