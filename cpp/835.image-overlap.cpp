class Solution {
public:
    int maxOverlap(vector<vector<int> > &mat1, vector<vector<int> >  &mat2, int i, int j, int a, int b){
	    int n = mat1.size(), m = mat1[0].size();
	    int cont = 0;
	    for(int ii=i, aa=a;ii<n && aa<n; ii++,aa++){
		    for(int jj = j, bb=b;jj<m && bb<m; jj++, bb++){
			    if(mat1[ii][jj]==1 && mat2[aa][bb]==1)cont++;
		    }
	    }
	    return cont;
    }
    int solve1(vector<vector<int>>& img1, vector<vector<int>>& img2) {
	    int n = img1.size(), m = img1[0].size();
	    int res = 0;
	    for(int i = 0 ; i < n; i++){
		    for(int j = 0 ; j < m ; j++){
			    for(int a = 0 ; a < n; a++){
				    for(int b = 0 ;b < m ;b++){
					    res = max(res, 
							    maxOverlap(img1, img2, i, j, a, b));
				    }
			    }
		    }
	    }
	    return res;
    }
    struct my_hash{
	    long long operator ()(const pair<int, int> &a) const{
		    auto h = hash<int>();
		    long long hash1 = h(a.first);
		    long long hash2 = h(a.second);
		    return hash1<<1 ^ hash2;
	    }
    };
    int solve2(vector<vector<int>>& img1, vector<vector<int>>& img2) {
	    int n = img1.size(), m = img1[0].size();
	    vector<tuple<int, int> > ones1, ones2;
	    for(int i = 0 ; i < n; i++){
		    for(int j = 0 ; j < m ; j++){
			    if(img1[i][j] == 1) ones1.push_back({i,j});
			    if(img2[i][j] == 1)ones2.push_back({i,j});
		    }
	    }
	    unordered_map<pair<int, int>, int, my_hash> freq;
	    int res =0 ;
	    for(auto [r1,c1]:ones1){
		    for(auto [r2,c2]:ones2){
			    long long dr = r2-r1;
			    long long dc = c2-c1;
			    pair<int, int> key(r2-r1, c2-c1);
			    res = max(res, ++freq[key]);
		    }
	    }
	    return res;
    }
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
	   return solve2(img1, img2);
	   return solve1(img1, img2);
    }
};
//Last case:     [[0,1],[1,1]]↩ [[0,1],[1,0]]
//  0 1
//  1 1
//
//  0 1
//  1 0
