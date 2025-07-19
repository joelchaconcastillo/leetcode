/**
 * Definition for a category handler.
 * class CategoryHandler {
 * public:
 *     CategoryHandler(vector<int> categories);
 *     bool haveSameCategory(int a, int b);
 * };
 */
class Solution {
public:
    int solve(int n, CategoryHandler *category){
	    vector<int> cats(n, -1);
	    for(int i = 0; i < n ;i++){
		    if(cats[i]!=-1)continue;
		    cats[i] = i;
		    for(int j = i+1; j < n; j++){
			    if(cats[j] != -1)continue;
			    if(category->haveSameCategory(i, j)){
				    cats[j]=i;
			    }
		    }
	    }
	    sort(cats.begin(), cats.end());
	    auto last = unique(cats.begin(), cats.end());
	    cats.erase(last, cats.end());
	    return cats.size();
    }
    int numberOfCategories(int n, CategoryHandler* categoryHandler) {
	    return solve(n, categoryHandler);
    }
};
