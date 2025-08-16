class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
	    int sec=1;
	    while(max(memory1, memory2)>=sec){
		    if(memory1 >= memory2) memory1-=sec;
		    else memory2 -=sec;
		    sec++;
	    }
	    return {sec, memory1, memory2};
    }
};
