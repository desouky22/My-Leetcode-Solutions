class Solution {
public:
    int n ,m ;
    vector<vector<char>> grid;
    vector<vector<bool>> vis;
    int dr[4] = {1,0,-1,0};
    int dc[4] = {0,1,0,-1};
    bool valid(int row, int col){
        return row>=0 and row<n and col>=0 and col<m;
    }
    bool dfs(int row, int col, int prevRow, int prevCol, char prev){
        if(!valid(row, col))return false;
        if(grid[row][col] != prev)return false;
        if(vis[row][col]){
            cout<<row<<" "<<col<<" "<<prevRow<<" "<<prevCol<<"\n";
            return true;
        }
        vis[row][col] = true;
        
        bool ret = false;
        for(int x = 0; x<4; x++){
            int newRow = row + dr[x], newCol = col + dc[x];
            if(newRow!=prevRow or newCol!=prevCol){
                ret = ret | dfs(newRow, newCol, row, col, prev);
            }
        }
        return ret;
    }
    
    bool containsCycle(vector<vector<char>>& g) {
        grid = g;    
        n = grid.size();
        m = grid[0].size();
        vis.resize(n, vector<bool>(m, false));
        
        for(int x = 0; x<n; x++){
            for(int y = 0; y<m; y++){
                if(!vis[x][y]){
                    cout<<x<<" "<<y<<"\n";
                    if(dfs(x, y, -1, -1, grid[x][y]))return true;
                }
            }
        }
        return false;
    }
};