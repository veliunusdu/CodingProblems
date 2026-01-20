#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

// Brute Force
class SolutionBrute {
    public:
    std::vector<int> maxSlidingWindow(std::vector<int>& nums, int k){
        std::vector<int> output;
        int n = nums.size();

        for(int i = 0; i<=n - k; i++){
            int maxi = nums[i];
            for(int j = i; j < i + k; j++){
                maxi =  std::max(maxi, nums[j]);
            }
            output.push_back(maxi);
        }
        return output;
    }
};



// Dynamic Programming
class SolutionDP {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> leftMax(n);
        vector<int> rightMax(n);

        leftMax[0] = nums[0];
        rightMax[n - 1] = nums[n - 1];

        for (int i = 1; i < n; i++) {
            if (i % k == 0) {
                leftMax[i] = nums[i];
            } else {
                leftMax[i] = max(leftMax[i - 1], nums[i]);
            }

            if ((n - 1 - i) % k == 0) {
                rightMax[n - 1 - i] = nums[n - 1 - i];
            } else {
                rightMax[n - 1 - i] = max(rightMax[n - i], nums[n - 1 - i]);
            }
        }

        vector<int> output(n - k + 1);

        for (int i = 0; i < n - k + 1; i++) {
            output[i] = max(leftMax[i + k - 1], rightMax[i]);
        }

        return output;
    }
};



// Deque
class SolutionDeque {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> output(n - k + 1);
        deque<int> q;
        int l = 0, r = 0;

        while (r < n) {
            while (!q.empty() && nums[q.back()] < nums[r]) {
                q.pop_back();
            }
            q.push_back(r);

            if (l > q.front()) {
                q.pop_front();
            }

            if ((r + 1) >= k) {
                output[l] = nums[q.front()];
                l++;
            }
            r++;
        }

        return output;
    }
};