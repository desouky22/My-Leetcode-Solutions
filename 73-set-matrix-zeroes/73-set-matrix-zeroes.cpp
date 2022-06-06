class Solution {
public:
   
    void setZeroes(vector<vector<int>>& matrix) {
        bool isZeroRow[matrix.size()];
        bool isZeroCol[matrix[0].size()];
        memset(isZeroRow, 0, sizeof isZeroRow);
        memset(isZeroCol, 0, sizeof isZeroCol);

        for(int x = 0; x<matrix.size(); x++){
            for(int y = 0; y<matrix[x].size(); y++){
                if(matrix[x][y] == 0)isZeroRow[x] = true, isZeroCol[y] = true;
            }
        }
        
        for(int x = 0; x<matrix.size(); x++){
            for(int y = 0; y<matrix[x].size(); y++){
                if(isZeroRow[x] or isZeroCol[y])matrix[x][y] = 0;
            }
        }
    }
};