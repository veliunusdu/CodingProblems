class Solution {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for (const string& s : strs) {
            res += to_string(s.length());
            res += '#';
            res += s;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.length()) {
            size_t delimiterPos = s.find('#', i);
            if (delimiterPos == string::npos) {
                // This case should ideally not be reached if encoding is correct
                // but handles malformed input or an empty last segment.
                break;
            }
            int length = stoi(s.substr(i, delimiterPos - i));
            i = delimiterPos + 1; // Move past '#'
            res.push_back(s.substr(i, length));
            i += length; // Move past the current string
        }
        return res;
    }
};


class Solutio2{
    public:
    string encode(vector<string>& strs){
        string res;
        for(const string& s:strs){
            res += to_string(s.size()) + "#" + s;
        }
        return res;
    }

    vector<string> decode(string s){
        vector<string> res;
        int i = 0;
        while(i<s.length()){
            size_t delimiterPos = s.find('#', i);
            if(delimiterPos == string::npos){
                break;
            }
            int length = stoi(s.substr(i, delimiterPos - i));
            i = delimiterPos + 1;
            res.push_back(s.substr(i, length));
            i += length;
        }
        return res;
    }
};
