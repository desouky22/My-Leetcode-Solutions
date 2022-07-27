class Solution {
public:
    int n,m;
    vector<vector<int>> grid;
    vector<vector<bool>> vis;
    int dr[4] = {0,1,0,-1};
    int dc[4] = {1,0,-1,0};
    
    bool valid(int row, int col){
        return row>=0 and row<n and col>=0 and col<m;
    }

    bool isClosedIsland(int row, int col){
        if(!valid(row, col))return false;
        if(vis[row][col])return true;
        if(grid[row][col] == 1) return true;
        vis[row][col] = true;
        bool ret = true;
        for(int x = 0; x<4; x++){
            ret = ret & isClosedIsland(row+dr[x], col+dc[x]);        
        }
        return ret;
    }
    
    int closedIsland(vector<vector<int>>& g) {
        grid = g;
        n = grid.size();
        m = grid[0].size();
        
        int ret = 0;
        vis.resize(n, vector<bool>(m));
        for(int x = 0; x<n; x++){
            for(int y = 0; y<m; y++){
                if(grid[x][y] == 0 and !vis[x][y]){
                    if(isClosedIsland(x, y))
                        ret ++;
                }
            }
        }
        return ret;
    }
    
};