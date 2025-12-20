class FoodRatings {
public:
    unordered_map<string, set<pair<int, string> > >cuisine2scores;
    unordered_map<string, string> food2cuisine;
    unordered_map<string, int> food2score;
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
	    for(int i = 0 ; i < foods.size(); i++){
		    food2score[foods[i]] = ratings[i];
		    food2cuisine[foods[i]] = cuisines[i];
		    cuisine2scores[cuisines[i]].insert({-ratings[i], foods[i]});
	    }
    }
    
    void changeRating(string food, int newRating) {
	    auto cuisine = food2cuisine[food];
	    cuisine2scores[cuisine].erase({-food2score[food], food});
	    food2score[food] = newRating;
	    cuisine2scores[cuisine].insert({-food2score[food], food});
    }
    
    string highestRated(string cuisine) {
	    return cuisine2scores[cuisine].begin()->second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */
