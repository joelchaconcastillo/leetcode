class Solution {
public:
    int solve1(int n) {
	    string str_n = to_string(n);
	    long long start = LLONG_MAX;
	    long long res = start, N = n;
	    sort(str_n.begin(), str_n.end());
	    do{
		    long long tmp = stoll(str_n);
		    if( tmp > N && tmp<res && tmp <= INT_MAX)res = tmp;
	    }while(next_permutation(str_n.begin(), str_n.end()));
	    if(res == start )return -1;
	    return res;
    }
    //                   ij
    // Last case:     230241
    // Last case:     230421
    // Last case:     230412
    // Expected:      230412
    int solve2(int n) {
	    string st = to_string(n);
	    int i = st.size()-2;
	    while(i >= 0 && st[i] >= st[i+1]) i--;
	    if(i<0) return -1;
	    int j = st.size()-1;
	    // 3 2 1
	    while(st[j] <= st[i])j--;
	    swap(st[i], st[j]);
	    reverse(st.begin()+i+1, st.end());
	    auto res = stoll(st);
	    if(res <= INT_MAX) return res;
	    return -1;
    }
    int nextGreaterElement(int n) {
	    return solve2(n);
    }
};
///  1 3 2
///  2 3
///  monotonic decreasing stack
