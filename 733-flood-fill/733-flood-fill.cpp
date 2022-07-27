class Solution {
public:
    int color;
    int n, m;
    vector<vector<int>> graph;
    vector<vector<bool>> vis;
    void dfs(int row, int col, int color, int old){
        vis[row][col] = true;
        graph[row][col] = color;
        if(row + 1 < n and !vis[row+1][col] and graph[row+1][col] == old) dfs(row+1, col, color, old);
        
        if(row - 1 >= 0 and !vis[row-1][col] and graph[row-1][col] == old) dfs(row-1, col, color, old);

        if(col + 1 < m and !vis[row][col+1] and graph[row][col+1] == old) dfs(row, col+1, color, old);

        if(col - 1 >=0 and !vis[row][col-1] and graph[row][col-1] == old) dfs(row, col-1, color, old);

        
        
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int c) {
        graph = image;
        n = graph.size();
        m = graph[0].size();
        color = c;
        vis.resize(image.size(), vector<bool>(image[0].size() , false));
        dfs(sr, sc, color, image[sr][sc]);
        return graph;
    }
};