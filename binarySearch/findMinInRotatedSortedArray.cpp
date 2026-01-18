// Brute Force
class Solution{
    public:
    int findMin(vector<int>& nums){
        return *min_element(nums.begin(), nums.end());
    }
};

// Binary Search
class Solution{
    public:
    int findMin(vector<int> &nums){
        int res = nums[0];
        int left = 0;
        int right = nums.size() - 1;

        while(left <= right){
            if(nums[left] < nums[right]){
                res = min(res, nums[left]);
                break;
            }
            int mid = (right - left) / 2;
            res = min(res, nums[mid]);

            if(nums[mid] >= nums[l]){
                left = mid + 1;
            }
            else{
                right = mid - 1;
            }
        }
        return res;
    }
};


// Binary Search (lower bound)
class Solution1{
    public:
    int findMin(vector<int>& nums){
        int l = 0, r = nums.size() - 1;
        while(l < r){
            int m = l + (r - l) / 2;
            if(nums[m] < nums[r]){
                r = m;
            }
            else{
                l = m + 1;
            }
        }
        return nums[l];
    }
};