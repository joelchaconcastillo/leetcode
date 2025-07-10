/**
 * Definition for an infinite stream.
 * class InfiniteStream {
 * public:
 *     InfiniteStream(vector<int> bits);
 *     int next();
 * };
 */
class Solution {
public:
    ///////////
    // KMP algorithm
    vector<int> pre_process_KMP(vector<int> &pattern){
	    int j = 0, n = pattern.size();
	    vector<int> pref(n, 0);
	    for(int i = 1 ; i < n; i++){
		    j = pref[i-1];
		    while( j > 0 && pattern[j] != pattern[i])
			    j = pref[j-1];
		    if(pattern[j] == pattern[i]){
			    j++;
		    }
		    pref[i] = j;
	    }
	    return pref;
    }
    int solve1(InfiniteStream* stream, vector<int> &pattern){
	    vector<int> pref = pre_process_KMP(pattern);
	    int j = 0;
	    for(int i = 0; i < 1e6; i++){//95000
		    int current_bit = stream->next();
		    while( j > 0 && pattern[j] != current_bit)
			    j = pref[j-1];
		    if( pattern[j] == current_bit) j++;
		    if(j == pattern.size()) return i-pattern.size()+1;
	    }
	    return -1;
    }
    /////////////////
    //Rabin-Karp algorithm
    long long MOD = 1e9+7, BASE = 30;
    long long compute_hash(deque<int> &dq){
	    long long hash = 0;
	    for(int i = 0 ; i < dq.size(); i++)
		    hash = ( hash*BASE + dq[i])%MOD;
	    return hash;
    }
    int solve2(InfiniteStream *stream, vector<int> &pattern){
	    int n = pattern.size();
	    deque<int> pattern_dq(pattern.begin(), pattern.end());
	    deque<int> window_dq;
	    for(int i = 0 ;i < n; i++) window_dq.push_back(stream->next());
	    long long hash_window = compute_hash(window_dq);
	    long long hash_pattern = compute_hash(pattern_dq);
	    long long power = 1;
	    for(int i = 0 ; i+1 < n; i++) power = (power*BASE)%MOD;
	    for(int i = 0 ; i < 1e6; i++){
		    if(hash_window == hash_pattern && pattern_dq == window_dq) return i;
		    int prev_val = window_dq.front(); window_dq.pop_front();
		    int next_val = stream->next(); window_dq.push_back(next_val);
		    hash_window = (hash_window - prev_val*power % MOD +MOD)%MOD;
		    hash_window = (hash_window*BASE + next_val)%MOD;
	    }
	    return -1;
    }
    int findPattern(InfiniteStream* stream, vector<int>& pattern) {
	    return solve2(stream, pattern);
	    return solve1(stream, pattern);
    }
};
