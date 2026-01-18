// Recursive Binary Search
class Solution{
    public:
    int binarySearch(int l, int r, vector<int>& nums, int target){
        if(l > r) return -1;
        int m = l + (r - l) / 2;
        if(nums[m] == target) return m;
        return ((nums[m] < target) ? 
        binarySearch(m + 1, r, nums, target) :
        binarySearch(l, m - 1, nums, target));
    }

    int search(vector<int>& nums, int target){
        return binarySearch(0, nums.size() - 1, nums, target);
    }
};


// Iterative Binary Search
class Solution1{
    public:
    int binarySearch(int l, int r, vector<int>& nums, int target){
        int search(vector<int>& nums, int target){
            int l = 0, r = nums.size() - 1;
            while(l <= r){
            int m = l + (r - l) / 2;
            if(nums[m] > target){
                r = m - 1;
            }
            else if(nums[m] < target){
                l = m + 1;
            }
            else{
                return m;
            }
        }
        return -1;
    }
};


// Built-in Function
class Solution2{
    public:
        int search(vector<int>& nums, int target){
            auto it = lower_bound(nums.begin(), nums.end() target);
            return (it != nums.end() && *it == target) ? it - nums.begin() : -1;
        }
};