class Solution {
public:
    struct edge{
        int to;
        int cost;
        edge(int to, int cost){
            this->to = to;
            this->cost = cost;
        }
    };
    typedef vector<vector<edge>> GRAPH;
    vector<vector<int>> grid;
    int dr[4] = {0,1,0,-1};
    int dc[4] = {1,0,-1,0};
    int n , m, nodes;
    bool validIndex(int row, int col){
        return row>=0 and row<n and col>=0 and col<m;
    }
    
    vector<bool>vis;
    bool dfs(int node, int mid, GRAPH& graph){
        if(node == n*m) return true;
        vis[node] = true;
        bool ret = false;
        for(auto adj : graph[node]){
            if(!vis[adj.to]){
                if(adj.cost <= mid){
                    ret = ret | dfs(adj.to, mid, graph);
                }
            }
        }
        return ret;
    }
    
    
    bool valid(int mid, GRAPH& graph){
        vis.clear();
        vis.resize(nodes+1, false);
        return dfs(1, mid, graph);
    }
    
    
    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        nodes = n * m;
        GRAPH graph = vector<vector<edge>> (nodes+1);
        int node = 1;
        grid = heights;
        
        for(int x = 0; x<heights.size(); x++){
            for(int y = 0; y<heights[x].size(); y++){
                grid[x][y] = node++;
            }
        }
        
        for(int x = 0; x<n; x++){
            for(int y = 0; y<m; y++){
                int from = grid[x][y];
                for(int z = 0; z<4; z++){
                    int newRow = x + dr[z];
                    int newCol = y + dc[z];
                    if(validIndex(newRow, newCol)){
                        int to = grid[newRow][newCol];
                        graph[from].push_back(edge(to, abs(heights[x][y] - heights[newRow][newCol])));
                    }
                }
            }
        }
        int left = -1, right = 1e6;
        while(right - left != 1){
            int mid = (left + right) / 2;
            if(valid(mid, graph)) right = mid;
            else left = mid;
        }
        return right;
    }
};