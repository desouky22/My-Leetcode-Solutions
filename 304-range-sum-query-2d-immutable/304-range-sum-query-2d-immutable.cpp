class NumMatrix {
public:
    vector<vector<int>> prefixSum;
    NumMatrix(vector<vector<int>>& matrix) {
        prefixSum.resize(matrix.size());
        for(int x = 0; x<matrix.size(); x++){
            prefixSum[x].resize(matrix[x].size());
            prefixSum[x][0] = matrix[x][0];
            for(int y = 1; y<matrix[x].size(); y++){
                prefixSum[x][y] = prefixSum[x][y-1] + matrix[x][y];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        int ret = 0;
        for(int x = row1; x<=row2; x++){
            if(col1 == 0)ret+= prefixSum[x][col2];
            else {
                ret+= prefixSum[x][col2] - prefixSum[x][col1-1];
            }
        }
        return ret;
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */