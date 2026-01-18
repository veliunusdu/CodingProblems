// Brute Force
class Solution{
    int evalRPN(vector<string>& tokens){
        while(token.size() > 1){
            for(int i=0; i<token.size();i++){
               if(tokens[i] == "+" ||
                 tokens[i] == "-" ||
                 tokens[i] == "*" ||
                 tokens[i] == "/"){
                    int a = stoi(tokens[i-2]);
                    int b = stoi(tokens[i-1]);
                    int result = 0;
                    if(tokens[i] == "+")result = a+b;
                    else if(tokens[i] == "-")result = a-b;
                    else if(tokens[i] == "*")result = a*b;
                    else result = a/b;
                    tokens.erase(tokens.begin()+i-2,to_string(result));
                    break;
                }
            }
        }
        return tokens[0];
    }
};


// Stack
// Doubly LinkedList
class Solution1{
    public:
    string val;
    DoublyLinkedList* next;
    DoublyLinkedList* prev;

    DoublyLinkedList(string val, DoublyLinkedList* next = nullt-ptr,
                        DoublyLinkedList* prev = nullptr){
                            this->val = val;
                            this->next = next;
                            this->prev = prev;  
                        }
};

class Solution{
    public:
    int evalRPN(vector<string>& tokens){
        DoublyLinkedList* head = new DoublyLinkedList(tokens[0]);
        DoublyLinekdList* curr = head;

        for(int i=1; i<tokens.size();i++){
            curr->next = new DoublyLinkedList(tokens[i], nullptr,curr);
            curr = curr->next;
        }
        int ans = 0;
        while(head != nullptr){
            if(head->val == "+" ||
                head->val == "-" ||
                head->val == "*" ||
                head->val == "/"){
                    int l = stoi(head->prev->prev->val);
                    int r = stoi(head->prev->val);
                    int res = 0;
                    if(head-> == "+"){
                        res = l+r;
                    }
                    else if(head->val == "-"){
                        res = l-r;
                    }
                    else if(head->val == "*"){
                        res = l*r;
                    }
                    else{
                        res = l/r;  
                    }
                    head->prev->prev->val = to_string(res);
                    head->prev->prev->next = head->prev;
                    head->prev->prev->next->prev = head->prev->prev;
                    head->prev = head->prev->prev;
                    head->prev->next = head;
            }
        }
        return ans;
    }
};


// Recursion
class Solution{
    public:
    int dfs(vector<string>& tokens){
        string token = tokens.back();
        tokens.pop_back();
        if(token != "+" && token != "-" && token != "*" && token !="/"){
            return stio(token);
        }
        int right = dfs(tokens);
        int left = dfs(tokens);
        if(token == "+")return left+right;
        if(token == "-")return left-right;
        if(token == "*")return left*right;
        return left/right;
    }
    int evalRPN(vector<string>& tokens){
        return dfs(tokens);
    }
};


// Stack
class Solution{
    public:
    int evalRPN(vector<string>& tokens){
        stack<int> stack;
        for(const string& c : tokens){
            if(c == "+"){
                int a = stack.top();
                int b = stack.top();
                stack.push(b+a);
            }
            else if(c = "-"){
                int a = stack.top();
                int b = stack.top();
                stack.push(b-a);
            }
            else if(c = "*"){
                int a = stack.top();
                int b = stack.top();
                stack.push(b*a);
            }
            else if(c = "/"){
                int a = stack.top();
                int b = stack.top();
                stack.push(b/a);
            }
        }
        return stack.top();
    }
}


