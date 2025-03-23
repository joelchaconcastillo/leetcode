class Solution {
public:
    vector<int> parent, rank;
    int find_parent(int a){
	return parent[a] = (parent[a]!=a)?find_parent(parent[a]):a;
    }
    void union_sets(int a, int b){
	 int pa = find_parent(a), pb = find_parent(b);
	 if(pa==pb)return;
	 if(rank[pa] < rank[pb]){
            parent[pa] = pb;
	 }else{
	    parent[pb] = pa; 
	    if(rank[pa]==rank[pb])rank[pb]++;
	 }
    }
    int count_sets(){
	int n = parent.size();
	int counter = 0;
	for(int i = 0 ; i < n; i++){
	   if(find_parent(i)==i)counter++;
	}
	return counter;
    }
    int intersect(set<int> &arr_a, set<int> &arr_b){
	int counter = 0;
	for(auto i:arr_a){
	   if(arr_b.count(i))counter++;
	}
	return counter;
    }
    int solve(vector<vector<int> > &prop, int k){
	int n = prop.size(), m = prop[0].size();
	parent.assign(n, 0);
	rank.assign(n, 0);
	vector<set<int>> prop_sets(n);
	for(int i = 0 ; i < n; i++)parent[i]=i;
        for(int i = 0 ; i< n; i++){ // O(n*m)
	   for(int j = 0 ; j < m; j++){
	      prop_sets[i].insert(prop[i][j]);
	   }
	}
	for(int i = 0; i < n; i++){
	   for(int j = i+1; j < n; j++){
	       if(intersect(prop_sets[i], prop_sets[j])>=k){
		       union_sets(i, j);
	       }
	   }
	}
	return count_sets();
    }
    // time: O(n*n*(alpha(n))) where alpha is the Inverse Ackemann function ~ 5 for practical purposes..
    // space: O(n*m)
    // elapsed time to solve it: 10 min.
    int numberOfComponents(vector<vector<int>>& properties, int k) {
	return solve(properties, k);
    }
};
