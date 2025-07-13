class FileSystem {
public:
    unordered_map<string, int> paths; 
    FileSystem() {
       paths[""]=0; 
    }
    
    bool createPath(string path, int value) {
       string parent = path;
       while(!parent.empty() && parent.back()!='/')parent.pop_back();
       if(!parent.empty() && parent.back()=='/') parent.pop_back();
       if(paths.count(path) || !paths.count(parent))return false;
       paths[path]=value;
       return true;
    }
    
    int get(string path) {
       if(!paths.count(path)) return -1;
       return paths[path];
    }
};

/**
 * Your FileSystem object will be instantiated and called as such:
 * FileSystem* obj = new FileSystem();
 * bool param_1 = obj->createPath(path,value);
 * int param_2 = obj->get(path);
 */
