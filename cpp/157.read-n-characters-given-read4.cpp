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
     */
    int read(char *buf, int n) {
	    int _size = 0;
	    while(_size < n){
		 int bits = read4(buf);
		 if(bits==0) break;
		 int rem = n-_size;
		 _size += min(rem, bits);
		 buf += min(rem, bits);
	    }
	    return _size;
    }
};
