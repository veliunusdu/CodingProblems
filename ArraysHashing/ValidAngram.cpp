#include <algorithm>
#include <string>

using namespace std;

//Sorting
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) {
            return false;
        } else {
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            return s == t;
        }
    }
};

//Hashmap
class Solution2{
    public:
        bool isAnagram(string s, string t){
            if(s.size() != t.size()){
                return false;
            }
            unordered_map<char, int> countS;
            unordered_map<char, int> countT;
            for(int i=0;i< s.length(); i++){
                countS[s[i]]++;
                countT[t[i]]++;
            }
            return countS == countT;
        }
};


//HashTable(using array)//
class Solution3{
    public:
        bool isAnagram(string s, string t){
            if(s.size() != t.size()){
                return false;
            }
            int count[26] = {0};
            for(int i=0;i<s.length(); i++){
                count[s[i]-'a']++;
                count[t[i]-'a']--;
            }
            for(int i=0;i<26;i++){
                if(count[i] != 0){
                    return false;
                }
            }
            return true;
        }
}