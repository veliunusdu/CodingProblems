// Brute Force
class Solution{
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int len1 = nums1.size();
        int len2 = nums2.size();
        vector<int> merged(len1 + len2);
        copy(nums1.begin(), nums1.end(), merged.begin());
        copy(nums2.begin(), nums2.end(), merged.begin() + len1);
        sort(merged.begin(), merged.end());
        int total = len1 + len2;
        if(total % 2 == 0){
            return (merged[total / 2 - 1] + merged[total / 2]) / 2.0;
        }else{
            return merged[total / 2];
        }
    }
};


// Two Pointers
class Solution{
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        int len1 = nums1.size();
        int len2 = nums2.size();
        int i = 0, j = 0;
        int median1 = 0, median2 = 0;

        for(int count = 0; count < (len1 + len2) / 2 + 1; count++){
            median2 = median1;
            if(i < len1 && j < len2){
                if(nums1[i] > nums2[j]){
                    median1 = nums2[j];
                    j++;
                } else{
                    median1 = nums1[i];
                    i++;
                }
            } else if(i < len1){
                median1 = nums1[i];
                i++;
            } else{
                median1 = nums2[j];
                j++;
            }
        }
        if((len1 + len2) % 2 == 0){
            return (median1 + median2) / 2.0;
        }else{
            return median1;
        }
    }
};



// Binary Search
class Solution{
    public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2){
        vector<int> A = nums1;
        vector<int> B = nums2;
        int total = A.size() + B.size();
        int half = (total + 1) / 2;

        if(B.size() < A.size()){
            swap(A, B);
        }

        int l = 0;
        int r = A.size();
        while(l <= r){
            int i = (l + r) / 2;
            int j = half - i;

            int Aleft = i > 0 ? A[i - 1] : INT_MIN;
            int Aright = i < A.size() ? A[i] : INT_MAX;
            int Bleft = j > 0 ? B[j - 1] : INT_MIN;
            int Bright = j < B.size() ? B[j] : INT_MAX;

            if(Aleft <= Bright && Bleft <= Aright){
                if(total % 2 == 0){
                    return (max(Aleft, Bleft);
                }
                return max(Aleft, Bleft);
            }else if(Aleft > Bright){
                r = i - 1;
            }else{
                l = i + 1;
            }
        }
        return -1;
    }
};