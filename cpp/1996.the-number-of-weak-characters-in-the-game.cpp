class Solution {
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) {
        int res = 0, n = properties.size();
	map<int, vector<int> > prop;
	for(auto property:properties){
		prop[property[0]].push_back(property[1]);
	}
	int max_value = INT_MIN;
	for(auto it=prop.rbegin(); it!=prop.rend();it++){
		int new_max_value = max_value;
		for(auto end:it->second){
			if(max_value > end) res++;
			new_max_value = max(new_max_value, end);
		}
		max_value = new_max_value;
	}
	return res;
    }
};
//[[1,5],[10,4],[4,3]]
//
//  (1,5)   (4,3)   (10,4)
//     igg
//
//     3,4
//
//
//  [[1,1],[2,1],[2,2],[1,2]]
//    (1,1), (1,2), (2,1), (2,2)//                    i
//             i
//  2
//  [[7,9],[10,7],[6,9],[10,4],[7,5],[7,10]]
//    (6,9), (7,5), (7,9), (7,10), (10,4), (10,7)
//             i
//
