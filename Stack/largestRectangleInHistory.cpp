// Brute Force
class Solution{
    public:
    int largestRectangleArea(vector<int>& heights){
        int n = heights.size();
        int maxArea = 0;

        for(int i=0; i<n; i++){
            int height = heights[i];
            int rightMost = i+1;
            while(rightMost<n && heights[rightMost] >= height){
                rightMost++;
            }
            int leftMost = i;
            while(leftMost < n && heights[leftMost  ] >= height){
                leftMost--;
            }
            int width = rightMost - leftMost - 1;
            int area = width * height;
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
}


// Divide and Conquer
class MinIdx_Segtree{
    public:
        int n;
        const int INF = 1e9;
        vector<int> A;
        vector<int> tree;
        MinIdx_Segtree(int N, vector<int>& a){
            this->n = N;
            this->A = a;
            while(__builtin_popcount(n) != 1){
                A.push_back(INF);
                n++;
            }
            tree.resize(2*n);
            build();
        }
        void build(){
            for(int i=0;i<n;i++){
                tree[n+i] = i;
            }
            for(int j=n-1;j>=1;j--){
                int a=tree[j<<1];
                int b=tree[j<<1|1];
                if(A[a]<A[b]){
                    tree[j] = a;
                }
                else tree[j] = b;
            }
        }
        void update(int i, int val){
            A[i] = val;
            for(int j=(n+i)>>1; j>=1;j>>=1){
                int a = tree[j<<1];
                int b = tree[j<<1|1];
                if(A[a]<=A[b])tree[j] = a;
                else tree[j] = b;
            }
        }
        int query(int node, int l, int h, int ql, int qh){
            if(ql > h || qh < l) return INF;
            if(l >= ql && h <= qh) return tree[node];
            int mid = (l+h)>>1;
            int left = query(node<<1, l, mid, ql, qh);
            int right = query(node<<1|1, mid+1, h, ql, qh);
            return min(left, right);
        }   
};


class Solution{
    public:
    int getMaxArea(vector<int>& heights, int l; int r, MinIdx_Segtree& st){
        if(l>r) return 0;
        if(l==r) return heights[l];
        int MinIdx = st.query(1, 0, n-1, l, r);
        int left = getMaxArea(heights, l, MinIdx-1, st);
        int right = getMaxArea(heights, MinIdx+1, r, st);
        return max(left, right);    
    }
    int largestRectangleArea(vector<int>& heights){
        int n = heights.size();
        MinIdx_Segtree st(n, heights);
        return getMaxArea(heights, 0, n-1, st);
    }
};


// Stack
class Solution1{
    public:
    int largestRectangleArea(vector<int>& heights){
        int n = heights.size();
        vector<int> leftMost(n, -1);
        vector<int> rightMost(n, n);
        stack<int> stack;
        
        for(int i=0;i<n;i++){
            while(!stack.empty() && heights[stack.top()] >= heights[i]){
                stack.pop();
            }
            if(!stack.empty()){
                leftMost[i] = stack.top();
            }
            stack.push(i);
        }
        
    }
}