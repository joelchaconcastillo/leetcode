class Solution {
public:
    double rem_time(pair<int, int> &position_speed, int target){
	    return (target-position_speed.first+position_speed.second)/(static_cast<double>(position_speed.second));
    }
    int solve(int target, vector<int> &position, vector<int> &speed){
	    vector<pair<int, int> >pos_speed;
	    int n = position.size();
	    for(int i = 0 ; i < n; i++){
		    pos_speed.push_back({position[i], speed[i]});
	    }
	    sort(pos_speed.begin(), pos_speed.end());
	    vector<int> st;
	    for(int i = 0 ; i < n; i++){
		    while(!st.empty() && 
				    pos_speed[st.back()].second >= pos_speed[i].second &&
				    rem_time(pos_speed[st.back()], target) <=rem_time(pos_speed[i], target))
			 {
				    st.pop_back();
		    }
		    st.push_back(i);
	    }
	    return static_cast<int>(st.size());
    }
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
	    return solve(target, position, speed);
    }
};
