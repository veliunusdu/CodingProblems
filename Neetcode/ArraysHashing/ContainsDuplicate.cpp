#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

//Solution Brute Force
class Solution1{
    public:
    bool hasDuplicate(vector<int>& nums){
        for (int i = 0;i < nums.size(); i++){
            for(int j=i+1; j<nums.size();j++){
                if(nums[i] == nums[j]){
                    return true;
                }
            }
        }
            
        return false;
    }
};

//Solution Sorting
class Solution2{
    public:
    bool hasDuplicate(vector<int>& nums){
        sort(nums.begin(), nums.end());
        for(int i=1;i<nums.size(); i++){
            if(nums[i] == nums[i-1]){
                return true;
            }
        }
        return false;
    }
};


//Solution3 HashSet
class Solution3{
    public:
    bool hasDuplicate(vector<int>& nums){
        unordered_set<int> seen;
        for(int num:nums){
            if(seen.count(num)){
                return true;
            }
            seen.insert(num);
        }
        return false;
    }
};