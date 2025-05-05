class Solution {
public:
    int permutations(string &st, int i, unordered_map<int, bool> &marked){
	int counter = 1;
	for(int j = 0; j < st.size(); j++){
	   if(marked[j])continue;
	   marked[j]=true;
	   counter += permutations(st, j, marked);
	   marked[j]=false;
	   char prev=st[j];
	   while(j < st.size() && st[j]==prev)j++;j--;
	}
	return counter;
    }
    int solve(string &st){
	unordered_map<int, bool> marked;
	sort(st.begin(), st.end());
	return permutations(st, 0, marked)-1; //remove empty!!
    }
    int numTilePossibilities(string tiles) {
	return solve(tiles);
    }
};
/*
   Input: tiles = "AAB"
   Output: 8
   Explanation: The possible sequences are "A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
    i
   AAB
   j
   A
    A
     B  AAB
    B
     A  ABA
   A
    A
     B
    B
     A
   B
    A   
     A  BAA

     

 * */
