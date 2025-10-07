class Solution {
public:
	// buckets : pigs
	//     1   :  0 
	//     2   :  1
	//     3   :  2
	//     4   :  2
	//     5   :  3
	//     6   :  3
	//
	//     _ _ _
    //  x: pigs
    //  T: tests
    //  ans --> min_x (T+1)^x >= buckets -->
    //  log((T+1)^x) >= log(buckets)
    //  x*log(T+1)>=log(buckets)
    //  x >= log(buckets)/log(T+1)
    //  x >= log_{T+1}(buckets)
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
	    int T = minutesToTest/minutesToDie;
	    int states = T+1;
	    int pow = 1;
	    int pigs = 0;
	    while(pow < buckets){
		    pow *=states;
		    pigs++;
	    }
	    return pigs;
    }
};
