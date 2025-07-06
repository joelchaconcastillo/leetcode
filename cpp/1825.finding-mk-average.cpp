class FenwickTree{
	vector<long long> tree;
	public:
	        FenwickTree(){}
		FenwickTree(int n){
			tree.assign(n+1, 0);
		}
		void update(int index, int val){
		     for(;index < tree.size(); index += index&(-index)){
			     tree[index]+=val;
		     }
		}
		int query(int index){
		     int res = 0;
		     while(index > 0){
			     res +=tree[index];
			     index -= (index&(-index));
		     }
		     return res;
		}
		int getK(int val){
			int lo = 1, hi = tree.size()-1;
			while(lo < hi){
				int mid = (lo+hi)/2;
				if( val <= query(mid) ){
					hi=mid;
				}else{
					lo=mid+1;
				}
			}
			return lo;
		}
};
class MKAverage{
public:
    int m, k;
    FenwickTree sum, kth;
    list<int> stream;
    MKAverage(int m, int k):m(m), k(k) {
	    sum = FenwickTree(100000);
	    kth = FenwickTree(100000);
    }
    void addElement(int num) {
	    stream.push_back(num);
	    if(stream.size() > m){
		int val = stream.front();
		stream.pop_front();
		kth.update(val, -1);
		sum.update(val, -val);
	    }
	    kth.update(num, 1);
	    sum.update(num, num);
    }
    int calculateMKAverage() {
	    if(stream.size() < m )return -1;
	    int N = kth.query(100000);
	    int leftValue = kth.getK(k), rightValue = kth.getK(N-k);
	    int leftKth = kth.query(leftValue), rightKth = kth.query(rightValue);
	    int leftSum = sum.query(leftValue), rightSum = sum.query(rightValue);
	    while(leftKth-- > k) leftSum -=leftValue;//this is for repeated ones
	    while(rightKth-- > N-k) rightSum -=rightValue;
	    return (rightSum-leftSum)/(m-2*k);
    }
};


class MKAverage2{
public:
    list<int> stream;
    multiset<int> left_window, middle_window, right_window;
    long long sum_middle_window=0;
    int m , k;
    MKAverage2(int m, int k):m(m), k(k){
    }
    void remove_LRU(){
	    int num = stream.front();
	    stream.pop_front();
	    if(num <= *left_window.rbegin() ){
		    left_window.erase(left_window.find(num));
	    }else if(num <= *middle_window.rbegin()){
		    middle_window.erase(middle_window.find(num));
		    sum_middle_window -= num;
	    }else{
		    right_window.erase(right_window.find(num));
	    }
	    if(left_window.size() < k){
		    left_window.insert(*middle_window.begin());
		    sum_middle_window -= *middle_window.begin();
		    middle_window.erase(middle_window.begin());
	    }
	    if(middle_window.size() < m-2*k){
		    middle_window.insert(*right_window.begin());
		    sum_middle_window += *right_window.begin();
		    right_window.erase(right_window.begin());
	    }
    }
    void insert(int num){
	 left_window.insert(num);
	 stream.push_back(num);
	 if(left_window.size() > k){
	     middle_window.insert(*left_window.rbegin());
	     sum_middle_window += *left_window.rbegin();
	     left_window.erase(prev(left_window.end()));
	 }
	 if(middle_window.size() > m-2*k){
	     right_window.insert(*middle_window.rbegin());
	     sum_middle_window -= *middle_window.rbegin();
	     middle_window.erase(prev(middle_window.end()));
	 }
    }
    void addElement(int num) {
	    if(stream.size() >=m ) remove_LRU();
	    insert(num);
    }

    int calculateMKAverage() {
	    if(stream.size() < m)return -1;
	    return sum_middle_window / (m-2*k);
    }
};
/**
 * Your MKAverage object will be instantiated and called as such:
 * MKAverage* obj = new MKAverage(m, k);
 * obj->addElement(num);
 * int param_2 = obj->calculateMKAverage();
 */
