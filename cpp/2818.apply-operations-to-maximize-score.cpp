class Solution {
public:
    long long _pow(long long a, long long b, long long MOD){
	    long long res = 1;
	    while(b){
		 if(b&1) res = (res*a)%MOD;
		 a = (a*a)%MOD;
		 b >>=1;
	    }
	    return res;
    }
    unordered_map<int, int> primeScores;
    int getPrimeScore(int n){
	 int score = 0;
	 for(int i = 2; i <=sqrt(n) ;i++){ //8 4 2 1
		 if(n%i==0)score++;
		 while(n%i==0) n/=i;
	 }
	 if(n >=2) score++;//it is a prime number

	 return score;
    }
    int solve(vector<int> &nums, int k){
	int n = nums.size();
	vector<int> scores(n);
	for(int i =  0 ;i  < n; i++){
		scores[i] = getPrimeScore(nums[i]);
	}
	vector<long long> st, left(n,-1), right(n,n);
	for(int i = 0 ; i < n ;i++){
		while(!st.empty() && scores[st.back()] < scores[i]){
			right[st.back()] = i;
			st.pop_back();
		}
		if(!st.empty()) left[i] = st.back();
		st.push_back(i);
	}
	priority_queue<tuple<int, int> > pq;
	long long res=1, MOD = 1e9+7;
	for(int i = 0 ; i <n ;i++){
		pq.push({nums[i], i});
	}
	while(!pq.empty() && k>0){
		auto [num, idx] = pq.top(); pq.pop();
		long long opt = (long long)(left[idx]-idx)*(idx-right[idx]);
		long long taken = min((long long)k, opt);
		k-=taken;
		res = (res*((long long)_pow(num, taken, MOD))%MOD)%MOD;
	}
	return res;
    }
    int maximumScore(vector<int>& nums, int k) {
	    return solve(nums, k);
    }
};
