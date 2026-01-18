// Brute Force
class Solution{
    public:
    int maxArea(vector<int>& heights){
        int res = 0;
        for (int i = 0; i < height.size(); i++){
            for (int j = i + 1;j < height.size(); j++){
                res = max(res, min(heights[i], heights[j] * (j-i));)
            }
        }
        return res;
    }
};


// Two Pointer
class Solution1{
public:
    int maxArea(vector<int>& heights){
        int l  = 0;
        int r = heights.size() - 1;
        int res = 0;
        while (l < r){
            int area = min(heights[l], heights[r]) * (r - l);
            res = max(res, area);

            if ( heights[l] <= heights[r]){
                l++;
            }
            else{
                r--;
            }
        }
        return res;
    }
};

