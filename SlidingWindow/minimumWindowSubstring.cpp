#include <string>
#include <unordered_map>
#include <utility>
#include <climits>
using namespace std;

// Brute Force
class Solution {
public:
    string minWindow(string s, string t) {
        if (t.empty()) return "";

        unordered_map<char, int> countT;
        for (char c : t) {
            countT[c]++;
        }
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;

        for (int i = 0; i < (int)s.length(); i++) {
            unordered_map<char, int> countS;
            for (int j = i; j < (int)s.length(); j++) {
                countS[s[j]]++;

                bool flag = true;
                for (const auto& p : countT) {
                    char c = p.first;
                    int cnt = p.second;
                    if (countS[c] < cnt) {
                        flag = false;
                        break;
                    }
                }
                if (flag && j - i + 1 < resLen) {
                    resLen = j - i + 1;
                    res = {i, j};
                }
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};


// Sliding Window
class Solution2{
    public:
    string minWindow(string s, string t){
        if(t.empty()) return "";

        unordered_map<char, int> countT;
        for(char c : t){
            countT[c]++;
        }

        unordered_map<char, int> window;
       
        int have = 0, need = countT.size();
        pair<int, int> res = {-1, -1};
        int resLen = INT_MAX;
        int l = 0;

        for(int r = 0; r < s.length(); r++){
            char c = s[r];
            window[c]++;

            if(countT.count(c) && window[c] == countT[c]){
                have++;
            }

            while (have == need){
                if((r - l + 1) < resLen){
                    resLen = r - l + 1;
                    res = {l, r};
                }
                window[s[l]]--;
                if(countT.count(s[l]) && window[s[l]] < countT[s[l]]){
                    have--;
                }
                l++;
            }
        }
        return resLen == INT_MAX ? "" : s.substr(res.first, resLen);
    }
};