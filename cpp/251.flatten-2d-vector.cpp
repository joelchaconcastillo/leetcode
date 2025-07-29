class Vector2D {
public:
    Vector2D(vector<vector<int>>& vec):vec(vec) {
	    if(!vec.empty()){
	      this->row = this->vec.begin();
	      this->col = this->row->begin();
	    }
    }
    void update_col_row(){
	    if(this->row == this->vec.end()) return;
	    while(this->col == this->row->end()){
		    this->row++;
		    if(this->row == this->vec.end())return;
		    this->col = this->row->begin();
	    }
    } 
    int next() {
	    update_col_row();
	    int val = *col;
	    col++;
	    return val;
    }
    
    bool hasNext() {
	    update_col_row();
	    return this->row != this->vec.end();
    }
private:
    vector<vector<int> > vec;
    vector<vector<int> >::iterator row;
    vector<int>::iterator col;
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
