class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n = fruits.size(), m = baskets.size();	    
	int unplaced = n;
	for(auto fruit:fruits){
		for(int i = 0; i < m; i++){
			if(fruit <= baskets[i]){
				baskets[i] = 0;
				unplaced--;
				break;
			}
		}
	}
	return unplaced;
    }
};
