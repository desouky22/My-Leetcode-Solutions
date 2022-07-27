class Solution {
public:
    vector<vector<int>> visId;
    vector<vector<bool>> done;
    int dr[4] = {1,0,-1,0};
    int dc[4] = {0,1,0,-1};
    
    bool valid(int row, int col, vector<vector<int>>& grid){
        if(row<0 or row >= grid.size())return false;
        if(col<0 or col>=grid[0].size())return false;
        return true;
    }
    
    void dfs(int row, int col, int id, vector<vector<int>>& grid1){
        if(!valid(row, col, grid1))return;
        if(grid1[row][col] == 0) return;
        if(visId[row][col] != 0) return;
        if(visId[row][col] == id)return;
        visId[row][col] = id;
        for(int x = 0; x<4; x++){
            dfs(row+dr[x], col+dc[x], id, grid1);
        }
    }
    
    int dfs2(int row, int col, int id, vector<vector<int>>& grid2){
        if(!valid(row, col, grid2))return 0;
        if(grid2[row][col] == 0)return 0;
        if(done[row][col])return 0;
        int ret = 0;
        if(visId[row][col] != id) ret --;
        done[row][col] = true;
        for(int x = 0; x<4; x++){
            ret += dfs2(row+dr[x], col+dc[x], id, grid2);
        }
        return ret;
        
    }
    
    
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        int id = 1;
        visId.resize(n, vector<int>(m, 0));
        for(int x = 0; x<n; x++){
            for(int y = 0; y<m; y++){
                if(grid1[x][y] == 1 and visId[x][y] == 0){
                    dfs(x, y, id, grid1);
                    id ++;
                }
            }
        }
        
        done.resize(n, vector<bool>(m, false));
        int ret = 0;
        for(int x = 0; x<n; x++){
            for(int y = 0; y<m; y++){
                if(!done[x][y] and grid2[x][y] == 1 and visId[x][y] != 0){
                    if(dfs2(x, y, visId[x][y], grid2) == 0)ret++; 
                }
            }
        }
        return ret;
        
    }
};