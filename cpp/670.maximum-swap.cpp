class Solution {
public:
    // time: O(n*n)
    // space: O(n)
    // elapsed time to solve: 7 min.
    int solve_naive(int num){
      string st_num = to_string(num);
      int res = num, n = st_num.size();
      for(int i = 0 ; i < n; i++){
	  for(int j = i+1; j<n; j++){
		 swap(st_num[i], st_num[j]);
		 res = max(res, stoi(st_num));
		 swap(st_num[i], st_num[j]);
	  }
      }
      return res;
    }
    /*
        time: O(n)
        space: O(n)
     * */
    int solve(int num){
	string st = to_string(num);
	int n = st.size();
	int a = -1;
	bool open = false;
	for(int i = 0 ; i<n; i++){
	   if(i+1<n && st[i] < st[i+1]  && !open) open=true, a=i;
	   if(open && st[a] <= st[i]) a = i;
	}
	if(!open)return num;
	for(int i = 0; i < n; i++){
	   if(st[a] > st[i]){
		  swap(st[a], st[i]);
		  break;
	   }
	}
	return stoi(st);
    }
    int maximumSwap(int num) {
       return solve(num);
       return solve_naive(num);
    }
};
/*
  1993
  9 3

   2736
   2 7 3 6
   7 6

   12 5 10 9 6 7 8 11
   12 11
   
 * */
