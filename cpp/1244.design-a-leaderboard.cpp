class Leaderboard {
public:
    unordered_map<int, int> playerId_scores;
    set<pair<int, int> > scores_playerId;

    Leaderboard() {
        
    }
    
    void addScore(int playerId, int score) {
	    scores_playerId.erase({playerId_scores[playerId], playerId});
	    playerId_scores[playerId] +=score;
	    scores_playerId.insert({playerId_scores[playerId], playerId});
    }
    
    int top(int K) {
	    auto it = prev(scores_playerId.end());
	    int sum = 0;
	    K = min(K, (int)scores_playerId.size());
	    while(K){
		    sum +=it->first;
		    K--;
		    it--;
	    }
	    return sum;
    }
    
    void reset(int playerId) {
	    scores_playerId.erase({playerId_scores[playerId], playerId});
	    playerId_scores.erase(playerId);
    }
};

/**
 * Your Leaderboard object will be instantiated and called as such:
 * Leaderboard* obj = new Leaderboard();
 * obj->addScore(playerId,score);
 * int param_2 = obj->top(K);
 * obj->reset(playerId);
 */
