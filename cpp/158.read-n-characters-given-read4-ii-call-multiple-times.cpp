/**
 * The read4 API is defined in the parent class Reader4.
 *     int read4(char *buf4);
 */

class Solution {
public:
    /**
     * @param buf Destination buffer
     * @param n   Number of characters to read
     * @return    The number of actual characters read
     *   n < len
     *
     *   n >=len
     */
    char L1[4];
    int L1_size = 0, L1_index=0;
    int read(char *buf, int n) {
	    int total = 0;
	    while(L1_size > 0 && total < n){
		    buf[total++]=L1[L1_index++];
		    L1_size--;
	    }
	    if(L1_size==0)L1_index=0;
	    while(total < n){
		    int count = read4(L1);
		    if(count == 0)break;
		    int needed = min(n-total, count);
		    memcpy(buf+total,L1,needed);
		    total += needed;
		    if(needed < count){
			    L1_index = needed;
			    L1_size = count - needed;
		    }else{
			    L1_index = 0;
			    L1_size = 0;
		    }
	    }
	    return total;
    }
};
