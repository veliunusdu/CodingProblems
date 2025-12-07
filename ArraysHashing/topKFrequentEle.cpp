//Sorting
class Solution{
    public:
        vector<int> topKFrequent(vector<int>& nums, int k){
            unordered_map<int, int> count;
            for(int num:nums){
                count[num]++;
            }
            vector<pair<int, int>> arr;
            for(const auto& p:count){
                arr.push_back({p.second, p.first});
            }
            sort(arr.rbegin(), arr.rend());

            vector<int> ans;
            for(int i=0; i<k;i++){
                res.push_back(arr[i].second);
            }
            return res;
        }
};


//BucketSort
class Solution2{
    vector<int> topKFrequent(vector<int>& nums, int k){
        unoredered_map<int, int> count;
        for(int n : nums){
            count[n] = 1 + count[n];
        }
        for(const auto& entry : count){
            freq[entry.second].push_back(entry.first);
        }
        vector<int> res;
        for(int i=freq.size()-1;i>0;--i){
            for(int n:freq[i]){
                res.push_back(n);
                if (res.size() == k){
                    return res;
                }
            }
        }
        return res;
    }
};