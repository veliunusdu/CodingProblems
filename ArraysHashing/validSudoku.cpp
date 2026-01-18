//Brute Force
class Solution{
    public:
        bool isValidSudoku(vector<vector<char>>& board){
            for(int row=0; row<9; row++){
                unordered_set<char> rowSet;
                for(int i=0;i<9;i++){
                    if(board[row][i] == '.') continue;
                    if(rowSet.count(board[row][i])) return false;
                    rowSet.insert(board[row][i]);
                }
            }
            for(int col=0; col<9; col++){
                unordered_set<char> colSet;
                for(int i=0;i<9;i++){
                    if(board[i][col] == '.') continue;
                    if(colSet.count(board[i][col])) return false;
                    colSet.insert(board[i][col]);
                }
            }
            for(int i=0;i<9;i++){
                unordered_set<char> boxSet;
                for(int j=0;j<9;j++){
                    if(board[i][j] == '.') continue;
                    if(boxSet.count(board[i][j])) return false;
                    boxSet.insert(board[i][j]);
                }
            }
            return true;
        }
}   


//HashSet(one pass)
class Solution1{
    public:
        bool isValidSudoku(vector<vector<char>>& board){
            unordered_map<int, unoredered_set<char>> rows, cols, boxes;
            map<pair<int, int>, unordered_set<char>> boxes;
            for(int i=0;i<9;i++){
                for(int j=0;j<9;j++){
                    if(board[i][j] == '.') continue;
                    if(rows[i].count(board[i][j]) || cols[j].count(board[i][j]) || boxes[{i/3, j/3}].count(board[i][j])) return false;
                    rows[i].insert(board[i][j]);
                    cols[j].insert(board[i][j]);
                    boxes[{i/3, j/3}].insert(board[i][j]);
                }
            }
            return true;     
        }
}



//Bitmask
class Solution2{
    public:
        bool isValidSudoku(vector<vector<char>>& board){
            int rows[9] = {0};
            int cols[9] = {0};
            int boxes[9] = {0};

            for(int r=0;r<9;r++){
                for(int c=0;c<9;c++){
                    if(board[r][c] == '.') continue;
                    int num = board[r][c] - '0';
                    if(rows[r] & (1 << num)) return false;
                    if(cols[c] & (1 << num)) return false;
                    if(boxes[(r/3)*3 + c/3] & (1 << num)) return false;
                    rows[r] |= (1 << num);
                    cols[c] |= (1 << num);
                    boxes[(r/3)*3 + c/3] |= (1 << num);
                }
            }
            return true;
        }
}