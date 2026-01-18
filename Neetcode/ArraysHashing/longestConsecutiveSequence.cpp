// Brute Force
class Solution{
    public:
        int longestConsecutive(vector<int>& nums){
            int res = 0;
            unordered_set<int> numSet(nums.begin(), nums.end());
            for(int num : nums){
                int streak = 0; int curr = num;
                while(numSet.find(curr) != numSet.end()){
                    streak++;
                    curr++;
                }
                res = max(res, streak);
            }   
            return res;
        }
};

// Sorting
class Solution1{
    public:
        int longestConsecutive(vector<int>& nums){
            if(nums.empty()) return 0;
            sort(nums.begin(), nums.end());
            int res = 0, curr = nums[0], streak = 0, i=0;
            while(i<nums.size()){
                if(curr != size(nums)-1 && nums[curr] == nums[curr+1]){
                    curr = nums[i];
                    streak = 0;
                }
                while(i<nums.size() && nums[i] == curr){
                    i++;
                }
                streak++;
                curr++;
                res = max(res, streak);
            }
            return res;
        }
};


// HashSet
class Solution2{
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> numSet(nums.begin(), nums.end());
        int longest = 0;

        for (int num : numSet) {
            if (numSet.find(num - 1) == numSet.end()) {
                int length = 1;
                while (numSet.find(num + length) != numSet.end()) {
                    length++;
                }
                longest = max(longest, length);
            }
        }
        return longest;
    }
};


// HashMap
class Solution3{
    public:
        int longestConsecutive(vector<int>& nums){
            unordered_map<int, int> mp;
            int res = 0;
            for(int num : nums){
                if(!mp[num]){
                    mp[num] = mp[num - 1] + mp[num + 1] + 1;
                    mp[num - mp[num - 1]] = mp[num];
                    mp[num + mp[num + 1]] = mp[num];    
                }
                res = max(res, mp[num]);
            }
            return res;
        }
};