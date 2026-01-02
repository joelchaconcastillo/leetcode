class Solution {
public:
    bool checksuffix(vector<int> &sensor1, vector<int> &sensor2, int i){
	    return equal(sensor1.begin()+i+1, sensor1.end(), sensor2.begin()+i, sensor2.end()-1);
    }
    int badSensor(vector<int>& sensor1, vector<int>& sensor2) {
	    int n = sensor1.size();
	    int i = 0;
	    while( i < n && sensor1[i] == sensor2[i]) i++;
	    if(i == n)return -1;
	    auto res1 = checksuffix(sensor1, sensor2, i);
	    auto res2 = checksuffix(sensor2, sensor1, i);
	    if(res1 == res2)return -1;
	    if(res1)return 2;
	    return 1;
    }
};
/*
 *
 *  sensor1 = [2,3,4,5], sensor2 = [2,1,3,4]
 *
 *  2 3 4 5
 *    i
 *  2 1 3 4
 *      j
 *
 *   2 2 2 2 2
 *           i
 *   2 2 2 2 5
 *           j
 *
 *
 *  [1,2,3,2,3,2]↩ 
 *             i
 *  [1,2,3,3,2,3]
 *               j
 *
 *
 *  [1,2,3,1]↩ 
 *   i
 *            1
 *  [2,3,1,2]
 *   j
 *         1
 * */
