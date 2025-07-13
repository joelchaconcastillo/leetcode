class StringIterator {
public:
    string buffer;
    int current=0;
    StringIterator(string compressedString) {
	    int i = 0, n = compressedString.size();
	    while(i < n){
		 char letter = compressedString[i++];
		 string rep = "";
		 while(i< n && isdigit(compressedString[i]))rep+=compressedString[i++];
		 buffer += (string(stoi(rep), letter));
	    }
    }
    
    char next() {
	    if(current < buffer.size()){
		    return buffer[current++];
	    }
	    return ' ';
    }
    
    bool hasNext() {
	    return current < buffer.size();
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
