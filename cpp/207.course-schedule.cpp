class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    vector<int> ID(numCourses, 0);
        vector<vector<int>> AL(numCourses);
        for(auto i:prerequisites){
            AL[i[1]].push_back(i[0]);
            ID[i[0]]++;
        }
        queue<int> q;
        for(int i = 0; i < numCourses; i++) if(ID[i]==0) q.push(i);
        while(!q.empty()){
            auto i=q.front(); q.pop();
            for(auto j:AL[i]){
                ID[j]--;
                if(ID[j]==0)q.push(j);
            }
        }
        for(auto i:ID) if(i!=0)return false;
        return true;        
    }
};
