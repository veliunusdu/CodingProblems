// Sorting
#include <vector>
#include <algorithm>

class Solution{
    public:
    int findDuplicate(std::vector<int>& nums){
        std::sort(nums.begin(), nums.end());
        for(int i = 0; i<nums.size() - 1;i++){
            if(nums[i] == nums[i+1]){
                return nums[i];
            }
        }
        return -1;
    }
};


// fast and slow pointer
class SolutionFloyd {
    public:
    int findDuplicate(std::vector<int>& nums){
        int slow = nums[0];
        int fast = nums[0];
        while(true){
            slow = nums[slow];
            fast = nums[nums[fast]];
            if(slow == fast){
                break;
            }
        }
        int slow2 = 0;
        while(true){
            slow = nums[slow];
            slow2 = nums[slow2];
            if(slow == slow2){
                return slow;
            }
        }
    }
};
