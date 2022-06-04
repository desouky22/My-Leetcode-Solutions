class Solution {
public:
    vector<vector<string>>ans;
    vector<string>grid;int n;
    vector<bool>validRow , validCol;

    
    bool validInd(int idx){
        return idx>=0 and idx<n;
    }
    bool valid(){
    int numOfQueens = 0;
    for(int row = 0; row<n; row++){
        for(int col = 0; col<n; col++){
            if(grid[row][col] == 'Q'){
                numOfQueens++;
                //check row and col
                int val = 0;
                for(int z = 0; z<n; z++){
                    if(grid[row][z]=='Q')val++;
                    if(grid[z][col]=='Q')val++;
                }
                if(val > 2)return false;

                // check diagonals
                int Row = row ,Col = col;
                val = 0;
                while(validInd(Row) and validInd(Col)) {
                    if (grid[Row][Col] == 'Q') val++;
                    Row++, Col++;
                }
                if(val != 1)return false;

                Row = row ,Col = col;
                val = 0;
                while(validInd(Row) and validInd(Col)) {
                    if (grid[Row][Col] == 'Q') val++;
                    Row--, Col--;
                }
                if(val!=1)return false;

                Row = row ,Col = col;
                val = 0;
                while(validInd(Row) and validInd(Col)) {
                    if (grid[Row][Col] == 'Q') val++;
                    Row++, Col--;
                }
                if(val!=1)return false;

                Row = row ,Col = col;
                val = 0;
                while(validInd(Row) and validInd(Col)) {
                    if (grid[Row][Col] == 'Q') val++;
                    Row--, Col++;
                }
                if(val!=1)return false;
            }
        }
    }
    if(numOfQueens!=n)return false;
    return true;
}
 
void solve(int row){
    if(row == n){
        if(valid())ans.emplace_back(grid);
        return;
    }
    for(int col = 0; col<n; col++){
        if(validCol[col]) {
            grid[row][col] = 'Q';
            validCol[col] = 0;
            solve(row + 1);
            grid[row][col] = '.';
            validCol[col] = 1;
        }
    }
}

vector<vector<string>> solveNQueens(int para) {
    n = para;
    validCol.resize(n,1);
    validRow.resize(n,1);
    grid.resize(n);
    for(int x = 0; x<n;x++){
        grid[x] = string(n,'.');
    }
    solve(0);
    return ans;
        
        
    }
};