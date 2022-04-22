class MyHashMap {
public:
    vector<vector<pair<int,int>>> mp;
    int n = 1000;
    MyHashMap() {
        mp.resize(n);
    }
    
    void put(int key, int value) {
        int k = key % n;
        
        for(auto& x: mp[k]){
            if(x.first == key){
                x.second = value;
                return;
            }
        }
        mp[k].push_back({key, value});
    }
    
    int get(int key) {
        int k = key % n;
        for(auto&x : mp[k]){
            if(x.first == key){
                return x.second;
            }
        }
        return -1;
    }
    
    void remove(int key) {
        int myKey = key % n;
        int t = mp[myKey].size();
        for(int i = 0; i < t; i++) {
            auto& thing = mp[myKey][i];
            if(thing.first == key) {
                mp[myKey].erase(mp[myKey].begin() + i);
                return;
            }
        }
    }
};

/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */