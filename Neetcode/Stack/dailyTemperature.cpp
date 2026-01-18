// Brute Force
class Solution{
    public:
    vector<int> dailyTemperatures(vector<int>& temperatures){
        int n = temperatures.size();
        vector<int> ans(n,0);
        for(int i=0;i<n;i++){
            int count = 1;
            int j=i+1;
            while( j<n ){
                if(temperatures[j] > temperatures[i] ){
                    ans[i] = count;
                    break;
                }
                j++;
                count++;
            }
        }
        return ans;
    }   
};


// Stack
class Solution1{
    public:
        vector<int> dailyTemperatures(vector<int>& temperatures){
            vector<int> res(temperatures.size(), 0);
            stack<pair<int, int>> stack;
            for(int i=0; i<temperatures.size(); i++){
                int t = temperatures[i];
                while(!stack.empty() && t > stack.top().first){
                    auto pair = stack.top();
                    stack.pop;
                    res[pair.second] = i - pair.second;
            }
            stack.push({t, i});
        }
        return res;
    }
};


// Dynamic Programming
class Solution2{
    public:
    vector<int> dailyTemperatures(vector<int>& temperatures){
        int n = temperatures.size();
        vector<int> res(n, 0);

        for(int i=n-2; i>=0; i--){
            int j = i+1;
            while(j<n && temperatures[j] <= temperatures[i]){
                j = res[j];
            }
            if(j<n) res[i] = j-i;
        }
        return res;
    }
};