#include <unordered_map>
#include <string>
#include <algorithm>
using namespace std;

// Brute Force
class Solution{
    public:
    int characterReplacement(string s, int k){
        int res = 0;
        for(int i = 0; i < s.size(); i++){
            unordered_map<char, int> count;
            int maxf = 0;
            for(int j = i; j < s.size(); j++){
                count[s[j]]++;
                maxf = max(maxf, count[s[j]]);
                if((j - i + 1) - maxf <= k){
                    res = max(res, j - i + 1);
                }
            }
        }
        return res;
    }
};



// Sliding Window
class Solution1{
    public:
    int characterReplacement(string s, int k){
        unordered_map<char, int> count;
        int res = 0;

        int l = 0; int maxf = 0;
        for(int r = 0; r < s.size(); r++){
            count[s[r]]++;
            maxf = max(maxf, count[s[r]]);
            while((r - l + 1) - maxf > k){
                count[s[l]]--;
                l++;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};