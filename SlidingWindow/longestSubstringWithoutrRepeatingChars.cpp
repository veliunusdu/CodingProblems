#include <unordered_set>
#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

// BRUTE FORCE
class Solution{
    public:
    int lengthOfLongestSubstring(string s){
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            unordered_set<char> charSet;
            for(int j = i; j < s.size(); j++){
                if(charSet.find(s[j]) != charSet.end()){
                    break;
                }
                charSet.insert(s[j]);
            }
            res = max(res, (int)charSet.size());
        }
        return res;
    }
};


// Sliding Window
class Solution1{
    public:
    int lengthOfLongestSubstring(string s){
        unordered_map<char, int> mp;
        int l = 0, res = 0;
        for(int r = 0; r < s.size(); r++){
            if(mp.find(s[r]) != mp.end()){
                l = max(mp[s[r]] + 1, l);
            }
            mp[s[r]] = r;
            res = max(res, r - l + 1);
        }
        return res;
    }
};