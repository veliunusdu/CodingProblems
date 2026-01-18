// Reverse String
class Solution{
    public:
    bool isPalindrome(string s){
        string newStr = "";
        for(char c : s){
            if(isalnum(c)){
                newStr += tolower(c);
            }

        }
        return newStr == string(newStr.rbegin(), newStr.rend());
    }
};


// Two Pointers
class Solution1{
    public:
        bool isPalindrome(string s){
            int l=0, r=s.length()-1;
            while(l<r){
                while(l<r && !alphaNum(s[l])){
                    l++;
                }
                while(r>l && !alphaNum(s[r])){
                    r--;
                }
                if(tolower(s[l]) != tolower(s[r])){
                    return false;
                }
                l++, r--;
            }
            return true;
        }

        bool alphaNum(char c){
            return(c >= 'A' && c <='Z' ||
                    c >= 'a' && c <='z' ||
                    c >= '0' && c <='9');
        }
};