class Solution {
public:
    const int MOD = 1e9+7;
    int solve1(vector<int> &s){ //TLE!!!
	int n = s.size();
	long long res = 0 ;
	for(int i = 0; i < n; i++){ //starts at
	   long long minv = INT_MAX;
	   long long sum = 0;
	   for(int j = i; j < n; j++){
	      minv = min(minv, (long long)s[j]);
	      sum = (sum+s[j])%MOD;
	      res = ((res+minv*sum)%MOD);
	   }
	}
	return res;
    }
    int solve2(vector<int> &s){
	int n = s.size();
	vector<long long> prefix(n+1, 0);
	for(int i = 1; i <= n; i++) prefix[i] = prefix[i-1]+s[i-1];
	vector<long long> prefix2(n+2, 0);
	for(int i = 1; i <= n+1; i++)prefix2[i] = prefix2[i-1]+prefix[i-1];
	vector<int> left(n, -1), st;
	for(int i = 0; i < n; i++){
	   while(!st.empty() && s[st.back()] >= s[i])st.pop_back();
	   if(!st.empty())left[i] = st.back();
	   st.push_back(i);
	}
	vector<int> right(n, n); st.clear();
	for(int i = n-1; i>=0; i--){
	   while(!st.empty() && s[st.back()] > s[i])st.pop_back();
	   if(!st.empty()) right[i] = st.back();
	   st.push_back(i);
	}
	long long res = 0;
	for(int i = 0; i <n; i++){
	   long long _segment_a = (prefix2[right[i]+1]-prefix2[i+1])%MOD;
	   _segment_a = (_segment_a*(i-left[i]))%MOD; // --> [p'(r)-p'(i)]*(i-l) missing +1
	   long long _segment_b = (prefix2[i+1]-prefix2[left[i]+1])%MOD; // --> [p'(i)-p'(l)]*(r-i) missing +1
	   _segment_b = (_segment_b*(right[i]-i))%MOD;
	   res += ((_segment_a+MOD-_segment_b)%MOD)*s[i]%MOD;
	}
	return res%MOD;
    }
    int totalStrength(vector<int>& strength) {
	return solve2(strength);
    }
};
/*
   5 4 6
   l=left, r = right
   sum(l, r) -->  sum(l+1,i)+sum(l, i+1)+...+sum(l, r-1)
                + sum(l+1,i)+sum(l+1,i+1)+...+sum(l+1, r-1)
		+ ....
		+ sum(i,i) + sum(i,i+1)+...+sum(i,r-1)
            -->   (p[i+1]-p[l])+(p[i+2]-p[l])....
	          (p[i+1]-p[l+1])+(p[i+2]-p[l+1])....
		  (p[i+1]-

	    -->  (p[i+1]+p[i+2]+..+p[r])*(i-l)
	         (p[l+1]+p[l+1]+..+p[i+1])*(r-i)
		 (p2[r+1]-p2[i+1])*(i-l) - (p2[i+1]-p2[l+1])*(r-i)








 * */
