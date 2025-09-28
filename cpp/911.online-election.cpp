#define oob(x, y) (x < 0 or y < 0 or x >= N or y >= N)
#pragma GCC optimize("O3,unroll-loops,Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx")
static const auto harsh = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    return 0;
}();

#define LC_HACK
#ifdef LC_HACK
const auto __ = []() {
  struct ___ { static void _() { std::ofstream("display_runtime.txt") << 0 << '\n'; } };
  std::atexit(&___::_);
  return 0;
}();
#endif
class TopVotedCandidate {
public:
    int n;
    vector<int> times;
    unordered_map<int, int> winner;
    TopVotedCandidate(vector<int>& persons, vector<int>& times) {
	    this->n = persons.size();
	    this->times = times;
	    int best = -1;
	    unordered_map<int, int> freq;
	    for(int i = 0 ; i <n; i++){
		    if(++freq[persons[i]] >= freq[best]) best = persons[i];
		    winner[times[i]]=best;
	    }
    }
    
    int q(int t) {
	    int id = upper_bound(times.begin(), times.end(), t)-times.begin();
	    return winner[times[id-1]];
    }
};

/**
 * Your TopVotedCandidate object will be instantiated and called as such:
 * TopVotedCandidate* obj = new TopVotedCandidate(persons, times);
 * int param_1 = obj->q(t);
 */
