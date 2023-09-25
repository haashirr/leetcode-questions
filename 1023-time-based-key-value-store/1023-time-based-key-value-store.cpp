class TimeMap {
public:
    vector<pair<int,pair<string,string>>>v;
    TimeMap() {
        
    }
    
    void set(string key, string value, int timestamp) {
        v.push_back(make_pair(timestamp,make_pair(key,value)));
    }
    
    string get(string key, int timestamp) {
        for(int i=v.size()-1;i>=0;i--) {
            if(v[i].second.first==key) {
                if(v[i].first<=timestamp) {
                    return v[i].second.second;
                }
            }
        }
        return "";
    }
};

/**
 * Your TimeMap object will be instantiated and called as such:
 * TimeMap* obj = new TimeMap();
 * obj->set(key,value,timestamp);
 * string param_2 = obj->get(key,timestamp);
 */