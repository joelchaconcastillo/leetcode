class Solution {
public:
    int solve(vector<int> &nums, int k, int p){
	    int n = nums.size();
	    set<vector<int> > marked;
	    for(int i = 0 ; i < n; i++){
		    int sum = 0;
		    vector<int> tmp;
		    for(int j = i; j < n; j++){
			    sum += nums[j]%p==0;
			    if(sum>k)break;
			    tmp.push_back(nums[j]);
		            marked.insert(tmp);
		    }
	    }
	    return marked.size();
    }
    //rolling hash
    int solve2(vector<int> &nums, int k, int p) {
        int n = nums.size();
        vector<int> bin = nums;
        for (auto &i : bin) i = (i % p == 0);
    
        const long long mod1 = 1e9 + 7, base1 = 31;
        const long long mod2 = 1e9 + 11, base2 = 51;
    
        struct hash_pair {
            size_t operator()(const pair<long long, long long>& p) const {
                return hash<long long>()(p.first) ^ (hash<long long>()(p.second) << 1);
            }
        };
    
        unordered_set<pair<long long, long long>, hash_pair> marked;
    
        for (int i = 0; i < n; ++i) {
            int sum = 0;
            long long hash1 = 0, hash2 = 0;
            for (int j = i; j < n; ++j) {
                sum += bin[j];
                if (sum > k) break;
                hash1 = (hash1 * base1 + nums[j]) % mod1;
                hash2 = (hash2 * base2 + nums[j]) % mod2;
                marked.insert({hash1, hash2});
            }
        }
    
        return marked.size();
    }
    class Node{
	    public:
	    unordered_map<int, Node*> _to;
	    int cnt = 0;
		    Node(){
		    }
    };
    class Trie{
	    Node *root;
	    public:
		    Trie(){
			    root = new Node();
		    }
		    int insert(vector<int> &nums, int pos, int k, int p){
			    auto current = root;
			    int cont = 0, res = 0;
			    while(current && pos < nums.size() && cont <= k){
				    int id = nums[pos];
				    cont += ((id%p)==0);
				    if(cont>k) break;
				    if(!current->_to.count(id)){
					    current->_to[id] = new Node();
				    }
				    current = current->_to[id];
				    res += current->cnt==0;
				    current->cnt++;
				    pos++;
			    }
			    return res;
		    }
    };
    int solve3(vector<int> &nums, int k, int p){
	    int n = nums.size(), res = 0;
	    Trie objTrie;
	    for(int i = 0 ;i < n ;i++){
		    res += objTrie.insert(nums,i,k,p);
	    }
	    return res;
    }
    int countDistinct(vector<int>& nums, int k, int p) {
	    return solve3(nums, k, p);
	    return solve2(nums, k, p);
	    return solve(nums, k, p);
    }
};
