// Brute Force
class Solution{
    public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        for(int r = 0; r < matrix.size(); r++){
            for(int c = 0; < matrix[r].size(); c++){
                if(matrix[r][c] == target){
                    return true;
                }
            }
        }
        return false;
    }
};


// Binary Search
class Solution1{
    public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        int ROWS = matrix.size();
        int COLS = matrix[0].size();

        int top = 0, bot = ROWS - 1;
        while(top <= bot){
            int row = (top + bot) / 2;
            int (target > amtrix[row][COLS - 1]){
                top = row + 1;
            }
            else if(target < maatrix[row][0]){
                bot = row - 1;
            }
            else{
                break;
            }
        }
        int row = (top + bot) / 2;
        int l = 0, r = COLS - 1,
        while (l <= r){
            int m = (l + r) / 2;
            if(target > matrix[row][m]){
                l = m + 1;
            }
            else if(target < matrix[row][m]){
                r = m - 1;
            }
            else{
                return true;
            }
        }
        return false;
    }
};


// Binary Search (One Pass)
class Solution2{
    public:
    bool searchMatrix(vector<vector<int>>& matrix, int target){
        if(matrix.empty() || matrix[0].empty()){
            return false;
        }
        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = 0;
        int high = rows * cols - 1;
        while(low <= high){
            int mid = low + (high - low) / 2;
            int row = mid / cols;
            int col = mid % cols;

            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                low = mid - 1;
            }
            else{
                high = mid - 1;
            }
        }
        return false;

    }
};

// Example usage:
/*
int main() {
    vector<vector<int>> matrix = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };
    int target = 3;
    
    if (searchMatrix(matrix, target)) {
        cout << "Target found." << endl;
    } else {
        cout << "Target not found." << endl;
    }
    return 0;
}
*/