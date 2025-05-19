class Solution {
public:
    using h3 = tuple<long long, long long, long long>;
    struct hash3 {
        size_t operator()(const h3 &t) const {
            size_t h1 = get<0>(t);
            size_t h2 = get<1>(t);
            size_t h3_ = get<2>(t);
            return h1 ^ (h2 << 1) ^ (h3_ << 2);
        }
    };

    vector<int> solve1(vector<string> &words){
	  unordered_map<h3, int, hash3> count ;
	  const long long MOD1 = 1e9+7, MOD2 = 1e9+9, MOD3 = 1e9+11;
	  const long long base1 = 27, base2 = 31, base3 = 26;
	  for(auto word:words){
	      long long hash1=0, hash2=0, hash3=0;
	      for(auto letter:word){
		      int val = letter-'a'+1;
		      hash1 = ((hash1*base1)%MOD1+val)%MOD1;
		      hash2 = ((hash2*base2)%MOD2+val)%MOD2;
		      hash3 = ((hash3*base3)%MOD3+val)%MOD3;
		      count[{hash1, hash2, hash3}]++;
	      }
	  }
	  vector<int> res;
	  for(auto word:words){
	      long long hash1=0, hash2=0, hash3=0;
	      int cnt = 0;
	      for(auto letter:word){
		      int val = letter-'a'+1;
		      hash1 = ((hash1*base1)%MOD1+val)%MOD1;
		      hash2 = ((hash2*base2)%MOD2+val)%MOD2;
		      hash3 = ((hash3*base3)%MOD3+val)%MOD3;
		      cnt += count[{hash1, hash2, hash3}];
	      }
	      res.push_back(cnt);
	  }
	  return res;
    }
    class Node{
	    public:
	  unordered_map<char, Node*>_to;
	  int count=0;
	  Node(){
	  }
    };
    class Trie{
	    public:
	  Node *root=NULL;
	  Trie(){
	      root = new Node();
	  }
	  void insert(string &st){
	       auto current = root;
	       for(auto letter:st){
		   if(!current->_to.count(letter)){
			current->_to[letter] = new Node();
		   }
		   current->_to[letter]->count++;
		   current = current->_to[letter];
	       }
	  }
	  int prefix_sum(string &st){
	      int res = 0;
	      auto current = root;
	      for(auto letter:st){
		  res += current->_to[letter]->count;
		  current = current->_to[letter];
	      }
	      return res;
	  }
    };
    vector<int> solve2(vector<string> &words){
	    Trie trie;
	    for(auto word:words){
		trie.insert(word);
	    }
	    vector<int> res;
	    for(auto word:words){
		res.push_back(trie.prefix_sum(word));
	    }
	    return res;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
	    return solve2(words);
	    return solve1(words);
    }
};
