class Solution {
public:
    char slowestKey(vector<int>& releaseTimes, string keysPressed) {
	    pair<int ,char> res(0, 1);
	    int prev = 0, n = releaseTimes.size();
	    for(int i  = 0 ; i < n; i++){
		    pair<int, char> tmp(releaseTimes[i]-prev, keysPressed[i]);
		    res = max(res, tmp);
		    prev = releaseTimes[i];
	    }
	    return res.second;
    }
};
