//Brute Force
class Solution{
    public:
        bool isValid(string s){
            while(true){
                size_t pos = string::npos;
                if((pos = s.find("()")) != string::npos){
                    s.erase(pos, 2);
                    continue;
                }
                if ((pos = s.find("{}")) != string::npos){
                    s.erase(pos, 2);
                    continue;
                }
                if ((pos = s.find("[]")) != string::npos){
                    s.erase(pos, 2);
                    continue;
                }
                return s.empty();
            }
        }
}   


//Stack
class Solution1{
    public:
    bool isValid(string s){
        std::stack<char> stack;
        std::unordered_map<char, char> closeToOpen = {
            {')', '('},
            {'}', '{'},
            {']', '['}  
        };
        for (char c : s){
            if(closeToOpen.count(c)){
                if(!stack.empty() && stack.top() == closeToOpen[c]){
                    stack.pop();
                }
                else{
                    return false;
                }
            }
            else{
                stack.push(c);
            }
        }
        return stack.empty();
    }
}