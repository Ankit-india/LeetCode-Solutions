class MyHashSet {
public:
    int mod;
    vector<vector<int>> set;
    MyHashSet() {
        mod = 1000;
        set.resize(mod);
    }
    
    void add(int key) {
        int k = key % mod;
        for(int x : set[k]) {
            if(x == key) return;
        }
        set[k].push_back(key);
    }
    
    void remove(int key) {
        int k = key % mod;
        auto ans = find(set[k].begin(), set[k].end(), key);
        if(ans != set[k].end()) {
            set[k].erase(ans);
        }       
    }
    
    bool contains(int key) {
        int k = key % mod;
        auto ans = find (set[k].begin(), set[k].end(), key);
        return ans != set[k].end();

    }

};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */