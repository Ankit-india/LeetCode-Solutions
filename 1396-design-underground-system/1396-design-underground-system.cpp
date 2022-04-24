class UndergroundSystem {
public:
    unordered_map<int,pair<string,int>> org;
    unordered_map<string,pair<int,int>> p;
    
    UndergroundSystem() {
        
    }
    
    void checkIn(int id, string stationName, int t) {
        org[id] = make_pair(stationName, t);
    }
    
    void checkOut(int id, string stationName, int t) {
        auto cIn = org[id];
        org.erase(id);
        
        string path = cIn.first + "_" + stationName;
        p[path].first += t - cIn.second;
        p[path].second += 1;
    }
    
    double getAverageTime(string startStation, string endStation) {
        string temp = startStation + "_" + endStation;
        auto r = p[temp];
        return (double) r.first / r.second;
    }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */