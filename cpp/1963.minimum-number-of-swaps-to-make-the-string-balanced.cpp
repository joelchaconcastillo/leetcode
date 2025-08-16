class Solution {
public:
    int solve(string &st){
	    int l = 0, r= st.size()-1, res=0;
	    int cont1=0, cont2=0;
	    while(l<r){
		    while(l<r && cont1 >=0){
			    if(st[l] == '[') cont1++;
			    else cont1--;
			    if(cont1<0)break;
			    l++;
		    }
		    while(l<r && cont2 >=0){
			    if(st[r] == '[')cont2--;
			    else cont2++;
			    if(cont2<0)break;
			    r--;
		    }
		    if(l<r && st[l] == ']' && st[r] == '['){
			    l++, r--, res++;
			    cont1=1; cont2=1;
		    }
	    }
	    return res;
    }
    int minSwaps(string s) {
	    return solve(s);
    }
};
///   "]  ]  ]  [  [  ["
///    l              r
///
///   "[  ]  ]  [  [  ]"
///       l        r
///
///   "[  ]  [  ]  [  ]"
///          l  r
