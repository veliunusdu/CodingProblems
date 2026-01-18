// Brute Force
class Solution{
    public:
    int trap(vector<int>& height){
        if(height.empty()){
            return 0;
        }

        int n = height.size();
        int res = 0;

        for(,nt i = 0; i < n; i++){
            int leftMax = height[i];
            int rightMax = height[i];

            for(int j = 0; j < i; j++){
                leftMax = max(leftMax, height[j]);
            }
            for(int j = i + 1; j < n; j++){
                leftMax = max(rightMax, height[j]);
            }
            res += min(leftMax, rightMax) - height[i];
        }
        return res;
    }
};


// Two Pointers
class Solution1{
    public:
    int trap(vector<int>& height){
        if(height.empty()){
            return 0;
        }

        int l = 0;
        int r = height.size() - 1;
        int leftMax = height[l];
        int rigthMax = height[r];
        int res = 0;
        while(l < r){
            if(leftMax < rightMax){
                l++;
                leftMax = max(leftMax, height[l]);
                res += leftMax - height[l];
            }
            else{
                r--;
                rightMax = max(rightMax, height[r]);
                res += rightMax - height[r];
            }
        }
        return res;
    }
};


// Stack
class Solution2{
    public:
        int trap(vector<int>& height){
            if(height.empty()){
                return 0;
            }

            stack<int> stk;
            int res = 0;

            for(int i = 0; i < height.size(); i++){
                while(!stk.empty() && height[i] > height[stk.top()]){
                    int mid  =height[stk.top()];
                    stk.pop();
                    if(!stk.empty()){
                        int right = height[i];
                        int left = height[stk.top()];
                        int h = min(right, left) - mid;
                        int w = i - stk.top() - 1;
                        res += h * w;
                    }
                }
                stk.push(i);
            }
            return res;
        }
};