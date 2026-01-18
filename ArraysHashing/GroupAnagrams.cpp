//Sorting
class Solution{
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs){
            unordered_map<string, vector<string>> mp;
            for(const auto& s: strs){
                string sortedS = s;
                sort(sortedS.begin(), sortedS.end());
                mp[sortedS].push_back(s);
            }
            vector<vector<string>> ans;
            for(auto it: mp){
                ans.push_back(it.second);
            }
            return ans;
        }
};

//HashTable
class Solution2{
    public:
        vector<vector<string>> groupAnagrams(vector<string>& strs){
            unordered_map<string, vector<string>> mp;
            for(const auto& s:strs){
                vector<int> count(26, 0);
                for(char c:s){
                    count[c - 'a']++;
                }
                string key = to_string(count[0]);
                for(int i=1; i<26; i++){
                    key += "," + to_string(count[i]);
                }
                mp[key].push_back(s);
            }
            vector<vector<string>> ans;
            for(auto it: mp){
                ans.push_back(it.second);
            }
            return ans;
        }
}