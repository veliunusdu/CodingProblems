// Brute Force
class TimeMap{
    public:
    unordered_map<string, vector<pair<int, string>>> map;
    TimeMap(){}
    void set(string key, string value, int timestamp){
        map[key].push_back({timestamp, value});
    }
    string get(string key, int timestamp){
        if(map.find(key) == map.end()){
            return "";
        }
        int seen = 0;
        for(auto& [time, _] : keyStore[key]){
            if(time <= timestamp){
                seen = max(seen, time);
            }
        }
        return seen == 0 ? "" : map[key][seen].back();
    }
};



// Binary Search (sorted map)
class TimeMap{
    public:
    unordered_map<string, map<int, string>> m;
    TimeMap(){}
    void set(string key, string value, int timestamp){
        m[key].insert({timestamp, value});
    }
    string get(string key, int timestamp){
        auto it = m[key].upper_bound(timestamp);
        return it == m[key].begin() ? "" :  prev(it)->second;
    }
};


// Binary Search (array)
class TimeMap{
    private:
    unordered_map<string, vector<pair<int, string>>> m;
    public:
    TimeMap(){}
    void set(string key, string value, int timestamp){
        m[key].emplace_back(timestamp, value);
    }
    string get(string key, int timestamp){
        auto& values = m[key];
        int left = 0, right = values.size() - 1;
        string result = "";
        
        while(left <= right){
            int mid  =left + (right - left) / 2;
            if(values[mid].first <= timestamp){
                result = values[mid].second;
                left = mid + 1;
            }else{
                right = mid - 1;
            }
        }
        return result;
    }
};