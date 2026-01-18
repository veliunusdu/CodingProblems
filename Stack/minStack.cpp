//Brute Force
class Solution{
    public:
    stack<int> stk;
    MinStack(){
    }

    void push(int value){
        stk.push(val);
    }

    void pop(){
        stk.pop();
    }

    int top(){
        return stk.top();
    }

    int getMin(){
        stack<int> temp = stk;
        int min = INT_MAX; 
        while(stk.size()){
            mini = min(mini, stk.top());
            tmp.push(stk.top());
            stk.pop();
        }

        while(temp.size()){
            stk.push(temp.top());
            temp.pop();
        }
        return min;
    }
};


// Two Stacks
class MinStack{
    private:
       std::stack<int> stk;
       std::stack<int> minStack;

    public:
    MinStack(){}
    void push(int val){
        stk.push(val);
        val = std::min(val, minStack.empty() ?
    val : minStack.top());
    minStack.push(val);
    }
    void pop(){
        stk.pop();
        minStack.pop();
    }
    int top(){
        return stk.top();
    }
    int getMin(){
        return minStack.top();
    }
}


//One Stack
class Solution1{
    private:
        std::stack<int> stk;
    public:
        MinStack(){}

        void push(int val){
            if(stack.empty()){
                stack.push(0);
                min = val;
            }
            else{
                stack.push(val - min);
                if(val < min) min = val; 
            }
        }
        void pop(){
            if(stack.empty())return;
            long pop = stack.top();
            stack.pop();
            if(pop < 0) min = min - pop;
        }
        int top(){
            return stack.empty() ? min : stack.top() + min;
        }   
        int getMin(){
            return min;
        }
}
