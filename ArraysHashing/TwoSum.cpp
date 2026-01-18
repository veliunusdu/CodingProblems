#include <vector>
#include <unordered_map>
#include <algorithm>
#include <utility>

//Brute Force Approach
class Solution1{
    public:
    std::vector<int> twosum(std::vector<int>& nums, int target){
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                if(nums[i]+nums[j]==target){
                    return {i,j};
                }
            }
        }
        return {};
    }
};

//Sorting
class Solution2{
    public:
    std::vector<int> twosum(std::vector<int>& nums, int target){
        std::vector<std::pair<int, int>> A;
        for(int i=0;i<nums.size();i++){
            A.push_back({nums[i], i});
        }
        std::sort(A.begin(), A.end());
        int i=0;
        int j=nums.size()-1;
        while(i<j){
            int cur = A[i].first + A[j].first;
            if(cur==target){
                return{
                    std::min(A[i].second, A[j].second),
                    std::max(A[i].second, A[j].second)
                };
            }
            else if(cur < target){
                i++;
            }else{
                j--;
            }
        }
        return{};
    }
};



//HashMap(two pass)
class Solution3{
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target){
        std::unordered_map<int, int> indices; // val->index
        for(int i=0; i<nums.size(); ++i){
            indices[nums[i]] = i;
        }
        for(int i=0; i<nums.size(); ++i){
            int diff = target - nums[i];
            if(indices.count(diff) && indices[diff] != i){
                return {i, indices[diff]};
            }
        }
        return {}; // Return empty vector if no solution is found
    }
};

