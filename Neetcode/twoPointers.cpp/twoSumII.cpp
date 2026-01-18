// Brute Force
class Solution{
    public:
       vector<int> twoSum(vector<int>& nummbers, int target){
        for(int i=0; i<numbers.size();i++){
            for(int j=i+1;j<numbers.szie();j++){
                if(numbers[i]+numbers[j]==target){
                    return{i+1, j+1};
                }
            }
        }
        return {};
    }
};


// HashMap
class Solution2{
    public:
    vector<int> twoSum(vector<int>& numbers, int target){
        unordered_map<int, int> mp;
        for(int i=0;i<numbers.size();i++){
            int tmp = target-numbers[i];
            if(mp.count(tmp)){
                return {mp[tmp], i+1};
            }
            mp[numbers[i]] = i+1;
        }
        return {};
    }
};


// Two Pointers
class Solution3{
    public:
    vector<int> twoSum(vector<int>& numbers, int target){
        int l=0, r=numbers.size()-1;
        while(l<r){
            int curSum = numbers[l] + numbers[r];
            if(curSum > target){
                r--;
            }
            else if(curSum < target){
                l++;
            }
            else{
                return {l+1, r+1};
            }
        }
        return {};
    }
};