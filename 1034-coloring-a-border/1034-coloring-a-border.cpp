class Solution {
public:
    vector<vector<int>> grid, vis;
    
    bool valid(int row, int col, int old){
        if(row < 0 or row >= grid.size())return false;
        if(col < 0 or col>=grid[0].size())return false;
        if(grid[row][col] != old)return false;
        if(vis[row][col])return false;
        return true;
    }
    
    bool validIndex(int row, int col){
        return row >= 0 and row<grid.size() and col>=0 and col<grid[0].size();
    }
    int dr[4] = {0,1,0,-1};
    int dc[4] = {1,0,-1,0};
    
    void dfs(int row, int col, int color, int old){
        if(!valid(row, col, old))return;
        vis[row][col] = 1;
        for(int x = 0; x<4; x++){
            dfs(row+dr[x], col+dc[x], color, old);
        }
    }
    
    vector<vector<int>> colorBorder(vector<vector<int>>& g, int row, int col, int color) {
        grid = g;
        vis.resize(grid.size(), vector<int>(grid[0].size(), 0));
        dfs(row, col, color, grid[row][col]);
        int n = grid.size();
        int m = grid[0].size();
        for(int x = 0; x<n; x++){
            for(int y = 0; y<m; y++){
                if(vis[x][y] == 1){
                    int ret = 0;
                    for(int dir = 0; dir<4; dir++){
                        if(validIndex(x+dr[dir], y+dc[dir])){
                            if(vis[x+dr[dir]][y+dc[dir]] == 1)ret++;
                        }
                    }
                    if(ret != 4) grid[x][y] = color;
                }
            }
        }
        
        return grid;
    }
};